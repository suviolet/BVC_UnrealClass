#include "Actor/MobilePlatform.h"

AMobilePlatform::AMobilePlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>("Platform Mesh");
}

void AMobilePlatform::BeginPlay()
{
	Super::BeginPlay();
	//DisplayMessage();

	if (PlatformMesh)
	{
		//StartingLocation = (*PlatformMesh).GetRelativeLocation(); // other way to access something from a pointer
		StartingLocation = PlatformMesh->GetRelativeLocation();
		Destination += PlatformMesh->GetComponentLocation();
	}
}

void AMobilePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickMovement(DeltaTime);
	CheckIfAtEnd();
}

void AMobilePlatform::TickMovement(float DeltaTime)
{
	if (bMovingForward)
	{
		MoveAlpha = FMath::Clamp(MoveAlpha += DeltaTime * MovementSpeed * MovementDampening, 0.f, 1.f);
	}
	else
	{
		MoveAlpha = FMath::Clamp(MoveAlpha -= DeltaTime * MovementSpeed * MovementDampening, 0.f, 1.f);
	}

	FVector NextLocation = FMath::Lerp(StartingLocation, Destination, MoveAlpha);

	PlatformMesh->SetRelativeLocation(NextLocation);
}

void AMobilePlatform::CheckIfAtEnd()
{
	if (MoveAlpha == 1.f && bMovingForward)
	{
		bMovingForward = false;
	}
	else if (MoveAlpha == 0.f && !bMovingForward)
	{
		bMovingForward = true;
	}
}

void AMobilePlatform::DisplayMessage()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from your console"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Magenta, TEXT("Hellon from your screen"));
	}
}
