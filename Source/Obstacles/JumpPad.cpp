// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"

#include "GameFramework/Character.h"

#pragma region CONSTRUCT

AJumpPad::AJumpPad()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MovingMesh");
	Mesh->SetupAttachment(RootComponent);
	TriggerBox->SetupAttachment(Mesh);
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region JUMP_FUNCTIONS

void AJumpPad::OnTriggered(AActor* OtherActor, bool IsColliding)
{
	if (IsColliding)
	{
		if (ACharacter* Character = Cast<ACharacter>(OtherActor))
		{
			Character->LaunchCharacter(LaunchDirection, true, false);
		}
	}
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////