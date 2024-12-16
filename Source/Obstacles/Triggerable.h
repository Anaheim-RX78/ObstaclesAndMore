// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Triggerable.generated.h"

USTRUCT(Blueprintable)
struct FMyStruct
{
	GENERATED_BODY()
public:

	UPROPERTY()
	AActor* SInteractor;
	UPROPERTY()
	bool SIsColliding;
};

UCLASS()
class OBSTACLES_API ATriggerable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerable();

protected:
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* TriggerBox;

	UFUNCTION(BlueprintCallable)
	FMyStruct OnTrigger(AActor* Interactor, bool isColliding);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
