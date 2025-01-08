// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Triggerable.h"
#include "DamageTrigger.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLES_API ADamageTrigger : public ATriggerable
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditAnywhere, Category = "Stats")
	float Damage;
	
};
