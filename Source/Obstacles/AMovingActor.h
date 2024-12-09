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

	UPROPERTY(EditAnywhere, Category = "Settings")
	float speed = 1;

	UPROPERTY(VisibleAnywhere)
	UBillboardComponent* TargetPoint;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadOnly)
	USceneComponent* ActorRoot;

	UPROPERTY(VisibleAnywhere)
	FVector TargetPosition;

	UPROPERTY(VisibleAnywhere)
	FVector InitialPosition;

	virtual void MoveActor();

	virtual void GetTargetLocation();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
