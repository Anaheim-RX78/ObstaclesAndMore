// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Damagable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBasicDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSTACLESANDMORE_API UDamagable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamagable();

	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.0f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	float Health;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float damageAmount);

	UPROPERTY(BlueprintAssignable)
	FBasicDeathDelegate OnDeath;
		
};
