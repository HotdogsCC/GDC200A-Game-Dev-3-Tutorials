// Fill out your copyright notice in the Description page of Project Settings.


#include "DespawnerComponent.h"

// Sets default values for this component's properties
UDespawnerComponent::UDespawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDespawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	if(GetWorld())
	{
		//Delegate to despawn actor after AliveTime amount of time
		GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandle, this, &UDespawnerComponent::DestroyThisActor, AliveTime);
	}
	// ...
	
}


// Called every frame
void UDespawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDespawnerComponent::DestroyThisActor()
{
	// Destroys actor, delegate function tied to SetTimer
	GetOwner()->Destroy();
}
