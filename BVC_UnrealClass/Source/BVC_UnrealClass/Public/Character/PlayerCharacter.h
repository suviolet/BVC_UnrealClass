#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "Camera/CameraComponent.h" //not necessary here
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class BVC_UNREALCLASS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* JumpAction; //old type of pointer
	TObjectPtr <UInputAction> JumpAction; //new type of pointer

private:
	UPROPERTY(EditAnywhere, Category = Camera)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = Camera)
	USpringArmComponent* CameraBoom;
};
