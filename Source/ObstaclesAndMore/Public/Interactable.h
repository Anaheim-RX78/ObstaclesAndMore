// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interactable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBasicInteractionDelegate);

UCLASS( ClassGroup=(Interaction), meta=(BlueprintSpawnableComponent) )
class OBSTACLESANDMORE_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractable();

	UPROPERTY(EditAnywhere, Category="Interaction")
	bool needInput;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Interaction")
	FString InteractionLabel;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FString GetInteractionLabel() const;

	void Interact();

	UPROPERTY(BlueprintAssignable)
	FBasicInteractionDelegate OnBasicInteractionDelegate;


	virtual void OnInteractionStart();
		
};