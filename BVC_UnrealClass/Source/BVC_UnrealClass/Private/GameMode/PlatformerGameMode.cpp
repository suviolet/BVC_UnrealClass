
#include "GameMode/PlatformerGameMode.h"
#include "UI/GameOverlay.h"

void APlatformerGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		GameOverlay = CreateWidget<UGameOverlay>(PlayerController, GameOverlayRef);
		if (GameOverlay)
		{
			GameOverlay->AddToViewport();
		}
	}
}

void APlatformerGameMode::ChangeScore(int ChangeAmount)
{
	CurrentScore += ChangeAmount;
	GameOverlay->UpdateScoreText(CurrentScore);
}
