// Fill out your copyright notice in the Description page of Project Settings.


#include "APlatform.h"

#pragma region CONSTRUCT

AAPlatform::AAPlatform()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(CubeMeshAsset.Object);
		Mesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.2f));
	}
}

void AAPlatform::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if ( isStatic == true )
	{
		for (UBillboardComponent* Target : Targets)
		{
			Target->DestroyComponent();
			Target = nullptr;
		}
		Targets.Empty();
	}
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region BEGINPLAY_FUNCTION

// Called when the game starts or when spawned
void AAPlatform::BeginPlay()
{
	Super::BeginPlay();
}

#pragma endregion BEGINPLAY_FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TICK_FUNCTION

// Called every frame
void AAPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveActor(DeltaTime);
	
}

#pragma endregion TICK_FUNCTION
