
#include "UI/GameOverlay.h"
#include "Components/TextBlock.h"

void UGameOverlay::UpdateScoreText(int CurrentScore)
{
	FString ScoreString = FString::Printf(TEXT("Score: %d"), CurrentScore);
	ScoreText->SetText(FText::FromString(ScoreString));
}
