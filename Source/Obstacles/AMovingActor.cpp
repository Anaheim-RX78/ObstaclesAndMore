// Fill out your copyright notice in the Description page of Project Settings.


#include "AMovingActor.h"

#pragma region CONSTRUCT

// Sets default values
AAMovingActor::AAMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	if (ActorRoot) RootComponent = ActorRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	if (Mesh) Mesh->SetupAttachment(RootComponent);

	TargetPoint = CreateDefaultSubobject<UBillboardComponent>(TEXT("TargetPoint"));
	if (TargetPoint)
	{
		TargetPoint->SetupAttachment(RootComponent);
		static ConstructorHelpers::FObjectFinder<UTexture2D> BillboardSprite(TEXT("/Engine/EditorResources/S_TargetPoint.S_TargetPoint"));
		TargetPoint->Sprite = BillboardSprite.Object;
	}
	
}

#pragma endregion CONSTRUCT
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region MOVEMESH_FUNCTION

void AAMovingActor::MoveActor(float movAlpha)
{

	Mesh->SetWorldLocation(FMath::Lerp(TargetPosition, InitialPosition, movAlpha));
	
}

void AAMovingActor::GetTargetLocation()
{

	InitialPosition = GetActorLocation();
	TargetPosition = TargetPoint->GetComponentLocation();
	
}

#pragma endregion MOVEMESH_FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region BEGINPLAY_FUNCTION

// Called when the game starts or when spawned
void AAMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

#pragma endregion BEGINPLAY_FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TICK_FUNCTION

// Called every frame
void AAMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma endregion TICK_FUNCTION
