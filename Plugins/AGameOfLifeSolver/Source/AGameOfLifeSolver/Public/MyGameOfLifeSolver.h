// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGameOfLifeSolver.generated.h"

UCLASS()
class AGAMEOFLIFESOLVER_API AMyGameOfLifeSolver : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyGameOfLifeSolver();

	// Variables and methods from the original Game of Life code
#define NI 20
#define NJ 50
	int32(*oldMatrix)[NJ + 2];
	int32(*newMatrix)[NJ + 2];
	int32 speed;

	virtual void Initialise();

	UFUNCTION(BlueprintCallable, Category = "Game of Life")
		int32 GetElement(int32 i, int32 j);

	UFUNCTION(BlueprintCallable, Category = "Game of Life")
		void SetElement(int32 i, int32 j, int32 val);

	UFUNCTION(BlueprintCallable, Category = "Game of Life")
		void TimeStep(int n);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
