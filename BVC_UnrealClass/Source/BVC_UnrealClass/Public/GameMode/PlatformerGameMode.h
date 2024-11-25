#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlatformerGameMode.generated.h"

UCLASS()
class BVC_UNREALCLASS_API APlatformerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ChangeScore(int ChangeAmount);

private:
	int CurrentScore = 0;
};
