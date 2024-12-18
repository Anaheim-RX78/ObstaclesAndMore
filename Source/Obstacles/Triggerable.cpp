// Fill out your copyright notice in the Description page of Project Settings.


#include "Triggerable.h"

#pragma region CONTRUCT

// Sets default values
ATriggerable::ATriggerable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(ActorRoot);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("Collider");
	TriggerBox->SetupAttachment(ActorRoot);

}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region OVERLAPS_FUNCTIONS

void ATriggerable::OnTriggered(AActor* CurrentActor, bool isColliding)
{
	
}

void ATriggerable::OnTriggerActor(AActor* OtherActor, bool isColliding)
{

	if (isColliding)
	{
		bool IsNewActor = Interactors.Num()== 0;
		for (AActor* Interactor : Interactors)
		{
			if (Interactor)
			{
				if (OtherActor == Interactor)
				{
					IsNewActor = false;
				}
				else
				{
					IsNewActor = true;
				}
				
			} else if (!Interactor) IsNewActor = true;
			
		}
		if (IsNewActor)
		{
			Interactors.Add(OtherActor);
			OnTriggered(OtherActor, true);
		}
	}
	
	if (!isColliding)
	{
		for (AActor* Interactor : Interactors)
		{
			if (Interactor)
			{
				if (Interactor == OtherActor)
				{
					Interactors.Remove(Interactor);
					OnTriggered(OtherActor, false);
				}
			}
		}
	}
}

void ATriggerable::OnTriggerStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) OnTriggerActor(OtherActor, true);
}

void ATriggerable::OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor) OnTriggerActor(OtherActor, false);
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region BEGINPLAY_FUNCTION

// Called when the game starts or when spawned
void ATriggerable::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATriggerable::OnTriggerStart);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATriggerable::OnTriggerEnd);
	
}

#pragma endregion
/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region TICK_FUNCTION

// Called every frame
void ATriggerable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma endregion