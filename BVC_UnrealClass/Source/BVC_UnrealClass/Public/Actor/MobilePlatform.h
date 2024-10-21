#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MobilePlatform.generated.h"

UCLASS()
class BVC_UNREALCLASS_API AMobilePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMobilePlatform();

	virtual void Tick(float DeltaTime) override;

	FVector StartingLocation;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true, Category= "Platform Information"))
	FVector Destination;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere);
	UStaticMeshComponent* PlatformMesh;

private:
	void TickMovement(float DeltaTime);
	void CheckIfAtEnd();
	void DisplayMessage();

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	bool bMovingForward = true;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float MoveAlpha = 0.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 1.f;
	float MovementDampening = .05f;
};
