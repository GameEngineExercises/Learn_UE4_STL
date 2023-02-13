// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STLVectorActor.generated.h"

UCLASS()
class APerson : public AActor
{
	GENERATED_BODY()
public:

	void Initialized(FString PersonName, int32 PersonScore)
	{
		Name = PersonName;
		Score = PersonScore;
	}

	/* Getter */
	FString GetName() { return Name; }
	int32 GetScore() {return Score; }

	/* Setter */
	void SetScore(int32 AvgScore) { Score = AvgScore; }
	
private:
	FString Name;
	int32 Score;
	
};

UCLASS()
class LEARN_UE4_STL_API ASTLVectorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTLVectorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	/* Getter */
	void PrintPersonData(TArray<APerson*>& Persons);
	
	/* Setter*/
	void CreatePerson(TArray<APerson*>& Persons);
	void GradeScore(TArray<APerson*>& Persons);
	
private:
	TArray<APerson*> PersonsContainer;
};
