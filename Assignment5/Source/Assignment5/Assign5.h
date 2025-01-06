// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Assign5.generated.h"

UCLASS()
class ASSIGNMENT5_API AAssign5 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAssign5();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FVector2D Coordinate;
	float Timer;
	int Count;
	int8 EventCount;
	float TotalDistance;

	void Move();
	int32 Step();
	float Distance(FVector2D start, FVector2D end);
	//int32 CreateEvent();

};
