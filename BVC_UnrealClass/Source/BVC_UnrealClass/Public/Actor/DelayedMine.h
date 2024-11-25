
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelayedMine.generated.h"

class USphereComponent;

UCLASS()
class BVC_UNREALCLASS_API ADelayedMine : public AActor
{
	GENERATED_BODY()
	
public:	
	ADelayedMine();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	void MineExplosion();

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> MineMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereOverlap;

	UPROPERTY(EditAnywhere, Category = "Mine Details")
	float CountdownTime = 5.f;

	FTimerHandle DelayedTimerHandler;

};
