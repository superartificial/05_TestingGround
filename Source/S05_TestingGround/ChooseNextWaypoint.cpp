// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto IndexName = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), IndexName);

	return EBTNodeResult::Succeeded;
}

