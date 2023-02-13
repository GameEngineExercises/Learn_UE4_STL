// Fill out your copyright notice in the Description page of Project Settings.


#include "Container/STLVectorActor.h"

// Sets default values
ASTLVectorActor::ASTLVectorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASTLVectorActor::BeginPlay()
{
	Super::BeginPlay();

	// 1. Create 5 Persons
	CreatePerson(PersonsContainer);
	//PrintPersonData(PersonsContainer); // for test (Print)

	// 2. SetScore
	GradeScore(PersonsContainer);

	PrintPersonData(PersonsContainer); // Final Score
	
}

// Called every frame
void ASTLVectorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASTLVectorActor::PrintPersonData(TArray<APerson*>& Persons)
{
	// Using iteration (Method 1)
	for (auto & Person : Persons)
	{
		UE_LOG(LogTemp, Warning, TEXT("Person Name: %s"), *Person->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Person Score: %d"), Person->GetScore());
	}
	
	// Using iteration (Method 2)
	// for(int32 Index =  0; Index != Persons.Num(); ++Index)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Person Name: %s"), *Persons[Index]->GetName());
	// 	UE_LOG(LogTemp, Warning, TEXT("Person Score: %d"), Persons[Index]->GetScore());
	// }

	// Using iteration (Method 3)
	// for(auto It = Persons.CreateConstIterator(); It; ++It)
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("Person Name: %s"), *(*It)->GetName());
	// 	UE_LOG(LogTemp, Warning, TEXT("Person Score: %d"), (*It)->GetScore());
	// }
	
}

void ASTLVectorActor::CreatePerson(TArray<APerson*>& Persons)
{
	FString NameSeed = "ABCDE";
	for(int32 i = 0; i < 5; i++)
	{
		FString PersonName = "Player";
		PersonName += NameSeed[i];

		APerson* Person = NewObject<APerson>();
		Person->Initialized(PersonName, 0);
		Persons.Add(Person);
	}
}

void ASTLVectorActor::GradeScore(TArray<APerson*>& Persons)
{
	
	for (auto & Person : Persons)
	{
		TMap<int32, int32> ScoreMap;

		// Set Score
		for(int32 i = 0; i < 10; i++) { ScoreMap.Add(ScoreMap.Num(), rand() % 41 + 60); } // Score : 60 ~ 100

		// Remove maximum & Minimum Score.
		ScoreMap.ValueSort([](const int32& A, const int32& B){	return A < B; });
		ScoreMap.Remove(ScoreMap.begin().Key()); // Remove minimum
		ScoreMap.ValueSort([](const int32& A, const int32& B){ return A > B; });
		ScoreMap.Remove(ScoreMap.begin().Key()); // Remove maximum

		int Sum = 0 ;
		for(auto & Score : ScoreMap){ Sum += Score.Value; }
		int Avg =  Sum / ScoreMap.Num();

		Person->SetScore(Avg);
	}
}

