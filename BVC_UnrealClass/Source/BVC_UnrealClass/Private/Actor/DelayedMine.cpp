

#include "Actor/DelayedMine.h"
#include "Components/SphereComponent.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h"


ADelayedMine::ADelayedMine()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereOverlap = CreateDefaultSubobject<USphereComponent>("Sphere Overlap");
	SetRootComponent(SphereOverlap);

	MineMesh = CreateDefaultSubobject<UStaticMeshComponent>("MineMesh Mesh");
	MineMesh->SetupAttachment(SphereOverlap);
}

void ADelayedMine::BeginPlay()
{
	Super::BeginPlay();

	SphereOverlap->OnComponentBeginOverlap.AddDynamic(this, &ADelayedMine::OnSphereOverlap); //& adress
}

void ADelayedMine::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Started Timer"));
		GetWorldTimerManager().SetTimer(DelayedTimerHandler, this, &ADelayedMine::MineExplosion, CountdownTime);
	}
}

void ADelayedMine::MineExplosion()
{
	UE_LOG(LogTemp, Warning, TEXT("Mine Exploded"));

	TArray<FHitResult> OutHits;

	bool bBlockingHit = UKismetSystemLibrary::SphereTraceMulti(
		this,
		GetActorLocation(),
		GetActorLocation(),
		100.f,
		ETraceTypeQuery::TraceTypeQuery8, //Collision preset
		false,
		TArray<AActor*>(),
		EDrawDebugTrace::ForDuration,
		OutHits,
		true
	);

	if (bBlockingHit)
	{
		for (FHitResult HitResult : OutHits)
		{
			if (APlayerCharacter* Player = Cast<APlayerCharacter>(HitResult.GetActor()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit the Player!"));
			}
		}
	}
}
