// Fill out your copyright notice in the Description page of Project Settings.


#include "Spike.h"


#pragma region CONSTRUCT

ASpike::ASpike()
{
	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>("MovingMesh");
	SpikeMesh->SetupAttachment(RootComponent);
	TriggerBox->SetupAttachment(SpikeMesh);

	Damage = 100;
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////

