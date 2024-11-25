#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameMode.generated.h"

class UGameOverlay;

UCLASS()
class BVC_UNREALCLASS_API APlatformerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ChangeScore(int ChangeAmount);

protected:
	virtual void BeginPlay() override;

private:
	int CurrentScore = 0;

	UPROPERTY(EditAnywhere, Category = UserInterface)
	TSubclassOf<UGameOverlay> GameOverlayRef;

	TObjectPtr<UGameOverlay> GameOverlay;
};
