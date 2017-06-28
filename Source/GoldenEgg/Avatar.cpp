// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "Avatar.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    InputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
    InputComponent->BindAxis("Strafe", this, &AAvatar::MoveRight);
    InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
    InputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);
}

void AAvatar::MoveForward(float amount)
{
    // 컨트롤러가 아직 설정되지 않았거나 이동 값이 0과 같은 값이라면 아래로 진입하지 않도록 합니다.
    if (Controller && amount) {
        FVector fwd = GetActorForwardVector();
        // AddMovementInput을 호출해 실제로 플레이어를 'fwd' 방향으로 'amount' 만큼 이동시킵니다
        AddMovementInput(fwd, amount);
    }
}

void AAvatar::MoveRight(float amount)
{
    if (Controller && amount) {
        FVector right = GetActorRightVector();
        AddMovementInput(right, amount);
    }
}

void AAvatar::MoveBackward(float amount)
{
    if (Controller && amount) {
        FVector fwd = -GetActorForwardVector();
        AddMovementInput(fwd, amount);
    }
}

void AAvatar::MoveLeft(float amount)
{
    if (Controller && amount) {
        FVector right = -GetActorRightVector();
        AddMovementInput(right, amount);
    }
}

void AAvatar::Yaw(float amount)
{
    AddControllerYawInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
    AddControllerPitchInput(200.f * amount * GetWorld()->GetDeltaSeconds());
}
