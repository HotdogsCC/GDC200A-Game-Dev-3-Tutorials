// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectSpawner.generated.h"

UCLASS()
class TICKTUTORIAL_API AObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectSpawner();

	UPROPERTY(EditAnywhere)
	float TimeBetweenSpawns = 1.0f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	float TimePassedSinceLastSpawn = 0.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnReferencedActor();

private:

};
