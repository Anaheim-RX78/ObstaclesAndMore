// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "AMovingActor.generated.h"

UCLASS()
class OBSTACLES_API AAMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMovingActor();

protected:

	UPROPERTY(EditAnywhere, category = "Settings")
	bool UpdateTargetChanges;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float speed = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int MovPoints = 2;

	UPROPERTY()
	int PrevMovPoints = 0;

	UPROPERTY()
	float movAlpha;

	UPROPERTY()
	int CurrentTargetIndex = 0;

	UPROPERTY()
	bool InvertMovement;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TArray<UBillboardComponent*> Targets;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* ActorRoot;

	UPROPERTY(VisibleAnywhere)
	FVector TargetPosition;

	UPROPERTY(VisibleAnywhere)
	FVector InitialPosition;

	
	UFUNCTION()
	virtual void MoveActor(float DTime);
	
	UFUNCTION()
	virtual void GetTargetLocation(int index);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
