// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMovingActor.h"
#include "ADoor.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLES_API AADoor : public AAMovingActor
{
	GENERATED_BODY()
public:

	AADoor();

	UFUNCTION(BlueprintCallable)
	virtual void Open();
	UFUNCTION(BlueprintCallable)
	virtual void Close();

protected:

	UPROPERTY()
	bool CanMove;

	virtual void BeginPlay() override;

private:

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
