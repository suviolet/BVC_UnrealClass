#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable.generated.h"

class UBoxComponent;

UENUM(BlueprintType)
enum class ECollectableValue : uint8
{
	ECV_Green = 1 UMETA(DisplayName = "Green"),
	ECV_Blue = 5 UMETA(DisplayName = "Blue"),
	ECV_Yellow = 10 UMETA(DisplayName = "Yellow"),
	ECV_Max = 0 UMETA(DisplayName = "Default MAX")
};

UCLASS()
class BVC_UNREALCLASS_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	ACollectable();

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> CollectableMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxOverlap;

	UPROPERTY(EditAnywhere, Category=Value)
	ECollectableValue Value = ECollectableValue::ECV_Green;

	UFUNCTION()
	void OnBoxOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UPROPERTY(EditDefaultsOnly)
	TMap<ECollectableValue, UMaterialInterface*> MaterialLibrary;
};
