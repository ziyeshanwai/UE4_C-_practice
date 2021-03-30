// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/UnrealString.h"
#include "Dom/JsonObject.h"
#include "Json.h"
#include "Serialization/JsonSerializer.h"
#include "MyActor_test.generated.h"


UCLASS()
class AIFA_METAHUMAN_API AMyActor_test : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor_test();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		void print_input_string(FString a);
	UFUNCTION(BlueprintCallable, Category = "AIFA|Tool")
	static	void loadAIFAjson(FString rootpath, FString filename, TArray<float>& Weights_array);
	UFUNCTION(BlueprintCallable, Category = "AIFA|Tool")
	static	void loadAIFAjson2(FString rootpath, FString filename, TArray<FString>names, TMap<FString, float>& weights_map);
	UFUNCTION(BlueprintCallable, Category = "AIFA|Tool")
	static void LoadBsNames(FString rootpath, FString filename, TArray<FString>& names);
	
};
