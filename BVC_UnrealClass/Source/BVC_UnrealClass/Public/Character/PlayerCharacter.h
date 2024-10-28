#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "Camera/CameraComponent.h" //not necessary here
//#include "InputActionValue.h" //not necessary here
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class BVC_UNREALCLASS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	//virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	void Movement(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	/*
		Inputs
	*/
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* JumpAction; //old type of pointer
	TObjectPtr <UInputAction> JumpAction; //TObjectPtr new type of pointer

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr <UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr <UInputAction> MoveAction;

private:
	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = Camera)
	USpringArmComponent* CameraBoom;
};
