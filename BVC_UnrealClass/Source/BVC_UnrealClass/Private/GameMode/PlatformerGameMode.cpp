
#include "GameMode/PlatformerGameMode.h"

void APlatformerGameMode::ChangeScore(int ChangeAmount)
{
	CurrentScore += ChangeAmount;
	UE_LOG(LogTemp, Warning, TEXT("Current Score: %d"), CurrentScore);
}
