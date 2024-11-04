#include "Character/Animations/CharacterAnimInstance.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	APawn* PlayerCharacterPawn = TryGetPawnOwner();

	if (PlayerCharacterPawn)
	{
		PlayerCharacter = Cast<APlayerCharacter>(PlayerCharacterPawn);

		if (PlayerCharacter)
		{
			MovementComponent = Cast<UCharacterMovementComponent>(PlayerCharacter->GetMovementComponent());
			bIsFalling = MovementComponent->IsFalling();
		}
	}
}

void UCharacterAnimInstance::NativeUpdateAnimation(float Deltaseconds)
{
	if (MovementComponent)
	{
		MoveSpeed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);

		UpdateYawRotation();
	}
}

FORCEINLINE void UCharacterAnimInstance::UpdateYawRotation()
{
	if (PlayerCharacter)
	{
		const FVector CurrentFacingDirection = PlayerCharacter->GetActorForwardVector();
		FVector CurrentVelocityDirection = MovementComponent->Velocity;
		CurrentVelocityDirection.Normalize();

		const float DotProduct = FVector::DotProduct(CurrentFacingDirection, CurrentVelocityDirection);

		YawRotation = FMath::RadiansToDegrees(FMath::Acos(DotProduct));

		const FVector CrossProduct = FVector::CrossProduct(CurrentFacingDirection, CurrentVelocityDirection);
	}
}
