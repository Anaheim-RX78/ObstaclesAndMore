// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Interactable.h"
#include "Interactor.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class OBSTACLESANDMORE_API UInteractor : public UCapsuleComponent
{
	GENERATED_BODY()

	UInteractor();

	UPROPERTY(editAnywhere, Category = "Settings")
	FName Tag;

private:

	UPROPERTY()
	bool canInteract = false;

	UPROPERTY()
	AActor* interactingActor;

public:
	
	UFUNCTION(BlueprintCallable)
	void OnAskInteract();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	
};
