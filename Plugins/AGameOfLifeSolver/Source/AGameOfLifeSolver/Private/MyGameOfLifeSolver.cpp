// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameOfLifeSolver.h"

// Sets default values
AMyGameOfLifeSolver::AMyGameOfLifeSolver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyGameOfLifeSolver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGameOfLifeSolver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




void AMyGameOfLifeSolver::Initialise()
{
	// implementation goes here
    
    // Allocate memory for oldMatrix and newMatrix
    oldMatrix = new int32[NI + 2][NJ + 2];
    newMatrix = new int32[NI + 2][NJ + 2];

    // Initialize matrices with 0s
    for (int i = 0; i <= NI + 1; i++)
    {
        for (int j = 0; j <= NJ + 1; j++)
        {
            oldMatrix[i][j] = 0;
            newMatrix[i][j] = 0;
        }
    }
}

int32 AMyGameOfLifeSolver::GetElement(int32 i, int32 j)
{
	return oldMatrix[i][j];
}

void AMyGameOfLifeSolver::SetElement(int32 i, int32 j, int32 val)
{
	// implementation goes here

      // Ensure that the specified indices are within bounds
    if (i >= 0 && i < NI && j >= 0 && j < NJ)
    {
        // Set the specified element to the given value
        oldMatrix[i + 1][j + 1] = val;
    }
}

void AMyGameOfLifeSolver::TimeStep(int n)
{
	// implementation goes here

    // Initialize the matrices with the initial board state
    for (int i = 1; i <= NI; i++)
    {
        for (int j = 1; j <= NJ; j++)
        {
            oldMatrix[i][j] = GetElement(i, j);
        }
    }

    // Run the simulation for n steps
    for (int step = 0; step < n; step++)
    {
        // Compute the new board state
        for (int i = 1; i <= NI; i++)
        {
            for (int j = 1; j <= NJ; j++)
            {
                int sum = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        sum += oldMatrix[i + di][j + dj];
                    }
                }
                sum -= oldMatrix[i][j];

                if (oldMatrix[i][j] == 1 && (sum < 2 || sum > 3))
                {
                    newMatrix[i][j] = 0;
                }
                else if (oldMatrix[i][j] == 0 && sum == 3)
                {
                    newMatrix[i][j] = 1;
                }
                else
                {
                    newMatrix[i][j] = oldMatrix[i][j];
                }
            }
        }

        // Swap the old and new matrices
        int32(*temp)[NJ + 2] = oldMatrix;
        oldMatrix = newMatrix;
        newMatrix = temp;
    }

    // Update the board state with the final computed state
    for (int i = 1; i <= NI; i++)
    {
        for (int j = 1; j <= NJ; j++)
        {
            SetElement(i, j, oldMatrix[i][j]);
        }
    }
}

