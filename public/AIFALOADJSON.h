// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Containers/UnrealString.h"
#include "Dom/JsonObject.h"
#include "Json.h"
#include "Serialization/JsonSerializer.h"
#include "AIFALOADJSON.generated.h"

/**
 * 
 */
UCLASS()
class AIFA_METAHUMAN_API UAIFALOADJSON : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AIFA|Tool")
	static void loadAIFAjson(FString rootpath, FString filename, TArray<float>& Weights_array);
	UFUNCTION(BlueprintCallable, Category = "AIFA|Tool")
		static void getJsonNames(int num, TArray<FString>& names_array);
	
};
