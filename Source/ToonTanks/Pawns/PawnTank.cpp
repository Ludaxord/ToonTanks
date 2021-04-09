// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
APawnTank::APawnTank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void APawnTank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	Rotate();
	Move();
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotateInput);
}

void APawnTank::CalculateMoveInput(float MoveValue) {
	MoveDirection = FVector(MoveValue * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotateInput(float RotateValue) {
	float rotateAmount = RotateValue * RotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator rotation = FRotator(0, rotateAmount, 0);
	RotationDirection = FQuat(rotation);
}

void APawnTank::Move() {
	AddActorLocalOffset(MoveDirection, true);
}

void APawnTank::Rotate() {
	AddActorLocalRotation(RotationDirection, true);
}
