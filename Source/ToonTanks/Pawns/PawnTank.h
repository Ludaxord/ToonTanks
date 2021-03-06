// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BasePawn.h"
#include "GameFramework/Pawn.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TOONTANKS_API APawnTank : public ABasePawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void CalculateMoveInput(float MoveValue);
	void CalculateRotateInput(float RotateValue);

	void Move();
	void Rotate();

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
	float RotateSpeed = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	FVector MoveDirection;
	FQuat RotationDirection;

};
