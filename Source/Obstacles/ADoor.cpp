// Fill out your copyright notice in the Description page of Project Settings.


#include "ADoor.h"

#pragma region CONSTRUCT

AADoor::AADoor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		MovMesh->SetStaticMesh(CubeMeshAsset.Object);
		MovMesh->SetRelativeScale3D(FVector(1.5f, 0.25f, 3.f));
	}
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region DOOR_FUNCTION

void AADoor::Open()
{
	InvertMovement = false;
	CurrentTargetIndex = 0;
	CanMove = true;
	movAlpha = 0;
}

void AADoor::Close()
{
	InvertMovement = true;
	CurrentTargetIndex = 1;
	CanMove = true;
	movAlpha = 0;
}

#pragma endregion	
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region BEGINPLAY_FUNCTION

// Called when the game starts or when spawned
void AADoor::BeginPlay()
{
	Super::BeginPlay();
	CurrentTargetIndex = 1;
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TICK_FUNCTION

// Called every frame
void AADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanMove)
	{
		if (InvertMovement && movAlpha >= 0.99)
		{
			CanMove = false;
			movAlpha = 1;
		}
		else if (!InvertMovement && movAlpha >= 0.99)
		{
			CanMove = false;
			movAlpha = 1;
		}
		
		MoveActor(DeltaTime);	
		
	}

}

#pragma endregion
