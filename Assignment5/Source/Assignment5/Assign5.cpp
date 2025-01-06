// Fill out your copyright notice in the Description page of Project Settings.


#include "Assign5.h"

// Sets default values
AAssign5::AAssign5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAssign5::BeginPlay()
{
	Timer = 0;
	Count = 0;
	EventCount = 0;
	TotalDistance = 0;
	Super::BeginPlay();
	
}

// Called every frame
void AAssign5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Timer += DeltaTime;
	if (Timer > 1.f && Count < 10)
	{
		UE_LOG(LogTemp, Display, TEXT("==== Step %d ===="), Count+1);
		Move();
		Timer -= 1.f;
		Count++;
	}
	if (Count == 10)
	{
		UE_LOG(LogTemp, Display, TEXT("==== Total ===="));
		UE_LOG(LogTemp, Display, TEXT("Event Count : %d"), EventCount);
		UE_LOG(LogTemp, Display, TEXT("Total Distance: %f"), TotalDistance);
		Count++;
	}
}

void AAssign5::Move() {
	float Probability = FMath::FRandRange(0.f, 1.f);
	UE_LOG(LogTemp, Log, TEXT("Probability : %f"), Probability);
	if (Probability > 0.5f)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Failed"));
	}
	else
	{
		FVector2D PrevCoord = Coordinate;
		Coordinate[0] += Step();
		Coordinate[1] += Step();

		float MoveDistance = Distance(PrevCoord, Coordinate);

		UE_LOG(LogTemp, Log, TEXT("Event Success"));
		UE_LOG(LogTemp, Log, TEXT("Current Coordinate : %f, %f"), Coordinate[0], Coordinate[1]);
		UE_LOG(LogTemp, Log, TEXT("Move Distance : %f"), MoveDistance);

		EventCount++;
		TotalDistance += MoveDistance;
	}
}

int32 AAssign5::Step() {
	return FMath::RandRange(0, 1);
}

float AAssign5::Distance(FVector2D start, FVector2D end)
{
	//return FVector2D::Distance(start, end);
	return FMath::Sqrt(FMath::Pow(start[0] - end[0], 2.f) + FMath::Pow(start[1] - end[1], 2.f));
}

