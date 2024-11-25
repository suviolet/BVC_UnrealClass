#include "Actor/Collectable.h"
#include "Components/BoxComponent.h"
#include "Character/PlayerCharacter.h"
#include "GameMode/PlatformerGameMode.h"

ACollectable::ACollectable()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxOverlap = CreateDefaultSubobject<UBoxComponent>("Box Overlap");
	SetRootComponent(BoxOverlap);

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>("Collectable Mesh");
	CollectableMesh->SetupAttachment(BoxOverlap);
}

void ACollectable::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if(MaterialLibrary.Contains(Value))
	{
		CollectableMesh->SetMaterial(0, MaterialLibrary[Value]);
	}
}

void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	BoxOverlap->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnBoxOverlap);
}

void ACollectable::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor))
	{
		CastChecked<APlatformerGameMode>(GetWorld()->GetAuthGameMode())->ChangeScore((int)Value);
		Destroy();
	}
}
