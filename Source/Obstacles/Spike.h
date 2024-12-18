// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTrigger.h"
#include "Spike.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLES_API ASpike : public ADamageTrigger
{
	GENERATED_BODY()

public:

	ASpike();

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpikeMesh;
};
