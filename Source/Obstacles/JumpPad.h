// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Triggerable.h"
#include "JumpPad.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLES_API AJumpPad : public ATriggerable
{
	GENERATED_BODY()

public:

	AJumpPad();

protected:

	UPROPERTY(EditAnywhere, Category = "Settings")
	FVector LaunchDirection;

	
	UPROPERTY(EditAnywhere)
	UMeshComponent* Mesh;
	

	virtual void OnTriggered(AActor* OtherActor, bool IsColliding) override;
	
};
