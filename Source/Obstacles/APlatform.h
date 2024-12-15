// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMovingActor.h"
#include "APlatform.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLES_API AAPlatform : public AAMovingActor
{
	GENERATED_BODY()

public:

	AAPlatform();

protected:

	UPROPERTY(EditAnywhere, Category = "Settings")
	bool isStatic = false;

	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;


private:

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
