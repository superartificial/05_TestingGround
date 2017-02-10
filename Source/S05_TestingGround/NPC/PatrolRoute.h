// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTINGGROUND_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsComp;

public:	
	// Sets default values for this component's properties
	UPatrolRoute();

	TArray<AActor*> getPatrolPoints() const { return PatrolPointsComp; }
	
};
