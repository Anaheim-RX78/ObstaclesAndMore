// Fill out your copyright notice in the Description page of Project Settings.


#include "AMovingActor.h"

#pragma region CONSTRUCT

// Sets default values
AAMovingActor::AAMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorRoot = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(ActorRoot);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	
}


void AAMovingActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (PrevMovPoints != MovPoints && UpdateTargetChanges)
	{
		PrevMovPoints = MovPoints;
		for (UBillboardComponent* Target : Targets)
		{
			Target->DestroyComponent();
			Target = nullptr;
		}
		Targets.Empty(); 
	
		for (int i = 0; i < MovPoints; i++)
		{
			FString TargetName = FString::Printf(TEXT("Target%d"), i);
			UBillboardComponent* Target = NewObject<UBillboardComponent>(this, UBillboardComponent::StaticClass());
			Target->SetupAttachment(RootComponent);
			//static ConstructorHelpers::FObjectFinder<UTexture2D> BillboardSprite(TEXT("/Engine/EditorResources/S_TargetPoint.S_TargetPoint"));
			//Target->Sprite = BillboardSprite.Object;
			Target->RegisterComponent();
		
			Targets.Add(Target);
		}
	}
}

#pragma endregion 
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region MOVEMESH_FUNCTION

void AAMovingActor::MoveActor()
{
	if (Targets.Num() > 0)
	{
		if (movAlpha >= 1)
		{
			movAlpha = 0;
			if (CurrentTargetIndex >= Targets.Num() - 1 && InvertMovement == false)
			{
				InvertMovement = true;
			}
			else if (CurrentTargetIndex <= 0 && InvertMovement == true)
			{
				InvertMovement = false;
			}

			if (!InvertMovement)
			{ CurrentTargetIndex++;
			} else {CurrentTargetIndex --;}
		
			GetTargetLocation(CurrentTargetIndex);
		}

		movAlpha = movAlpha + 0.01 * speed;
		Mesh->SetWorldLocation(FMath::Lerp(InitialPosition, TargetPosition, movAlpha));
	}
}

void AAMovingActor::GetTargetLocation(int index)
{
	if (Targets.Num() > 0)
	{
		InitialPosition = Mesh->GetComponentLocation();
		TargetPosition = Targets[index]->GetComponentLocation();
	}
}

#pragma endregion 
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region BEGINPLAY_FUNCTION

// Called when the game starts or when spawned
void AAMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	GetTargetLocation(CurrentTargetIndex);
	
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TICK_FUNCTION

// Called every frame
void AAMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

#pragma endregion
