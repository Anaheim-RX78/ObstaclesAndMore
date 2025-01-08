// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactor.h"


UInteractor::UInteractor()
{
	OnComponentBeginOverlap.AddDynamic(this, &UInteractor::OnOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UInteractor::OnOverlapEnd);
}

void UInteractor::OnAskInteract()
{
	if (canInteract)
	{
		UInteractable* InteractionCp = interactingActor->FindComponentByClass<UInteractable>();
		if (InteractionCp == nullptr){ return; }
		InteractionCp->Interact();
	}
}

void UInteractor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr){ return; }
	UInteractable* InteractionCp = OtherActor->FindComponentByClass<UInteractable>();
	if (InteractionCp == nullptr){ return; }
	interactingActor = OtherActor;
	if (InteractionCp->needInput == true)
	{
		canInteract = true;
	}
	else
	{
		InteractionCp->Interact();
	}
}

void UInteractor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr){ return; }
	UInteractable* InteractionCp = OtherActor->FindComponentByClass<UInteractable>();
	if (InteractionCp == nullptr){ return; }
	interactingActor = nullptr;
	if (InteractionCp->needInput == true)
	{
		canInteract = false;
	}
}