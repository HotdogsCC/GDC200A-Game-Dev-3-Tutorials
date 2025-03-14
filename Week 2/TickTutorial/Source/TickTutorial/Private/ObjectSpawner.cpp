// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectSpawner.h"

// Sets default values
AObjectSpawner::AObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(2.0f);
}

// Called every frame
void AObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimePassedSinceLastSpawn += DeltaTime;

	if(TimePassedSinceLastSpawn > TimeBetweenSpawns)
	{
		SpawnReferencedActor();
		TimePassedSinceLastSpawn = 0.0f;
	}

}

void AObjectSpawner::SpawnReferencedActor()
{
	GetWorld()->SpawnActor<AActor>(ActorToSpawn);
}

