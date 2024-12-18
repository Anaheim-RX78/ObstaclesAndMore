// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageTrigger.h"

#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"


void ADamageTrigger::OnTriggered(AActor* OtherActor, bool IsColliding)
{
	if (IsColliding)
	{
		InfertDamage(OtherActor);
	}
}

void ADamageTrigger::InfertDamage(AActor* OtherActor)
{
	if (ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		Character->TakeDamage(Damage, FDamageEvent(), nullptr, this );
	}
}

