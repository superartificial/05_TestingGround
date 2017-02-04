// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGround.h"
#include "ChooseNextWaypoint.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto IndexVal = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	AAIController* AIController = OwnerComp.GetAIOwner();

	UPatrolRoute* PatrolRoute = nullptr;
	PatrolRoute = AIController->GetPawn()->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
	TArray<AActor*> PatrolPoints = PatrolRoute->getPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}
	auto WaypointVal = BlackboardComp->GetValueAsObject(WaypointKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[IndexVal]);
	int NextIndex = (IndexVal + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	return EBTNodeResult::Succeeded;
}

