// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor_test.h"

// Sets default values
AMyActor_test::AMyActor_test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AMyActor_test::BeginPlay()
{
	

}

void AMyActor_test::LoadBsNames(FString rootpath, FString filename, TArray<FString>& name_arrays)
{
	FString path = rootpath + filename;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		FString errorMsg = path + "is not existed!";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

	FString JsonStr;
	if (FFileHelper::LoadFileToString(JsonStr, *(path)))
	{
		TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(JsonStr);
		TSharedPtr<FJsonObject> rRoot;

		if (FJsonSerializer::Deserialize(Reader, rRoot))
		{
		
			if (rRoot->HasField(TEXT("names")))
			{
				auto names = rRoot->GetArrayField(TEXT("names"));
				for (auto& name : names)
				{
					if (name.IsValid())
					{
						name_arrays.Add(name->AsString());
						//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, weight->AsString());
					}
					else
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "name is not valuid");
					}

				}

			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "it Has not Field");
			}
		}

	}
	else
	{
		FString errorMsg = "it is failed to load file";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}
}


void AMyActor_test::print_input_string(FString to_print)
{
	FString string = TEXT("hello world");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, string);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, to_print);
//	UE_LOG(LogTemp, Log, to_print);
	
}

void AMyActor_test::loadAIFAjson(FString rootpath, FString filename, TArray<float>& Weights_array)
{
	FString path = rootpath + filename;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		FString errorMsg = path + " is not exist!!";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

	FString JsonStr;
	if (FFileHelper::LoadFileToString(JsonStr, *(path)))
	{
		TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(JsonStr);
		TSharedPtr<FJsonObject> rRoot;

		if (FJsonSerializer::Deserialize(Reader, rRoot))
		{
			if (rRoot->HasField(TEXT("Frame")))
			{
				auto g_Ip = rRoot->GetIntegerField(TEXT("Frame"));
			}

			if (rRoot->HasField(TEXT("Weight")))
			{
				auto weights = rRoot->GetArrayField(TEXT("Weight"));
				for (auto& weight : weights)
				{
					if (weight.IsValid())
					{
						Weights_array.Add(weight->AsNumber());
					//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, weight->AsString());
					}
					else
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "weight is not valuid");
					}
					
				}
				
			}
		}
		
	}
	else
	{
		FString errorMsg = "¼ÓÔØÎÄ¼þÊ§°Ü.";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

}


void AMyActor_test::loadAIFAjson2(FString rootpath, FString filename, TArray<FString>names, TMap<FString, float>& weights_map)
{
	FString path = rootpath + filename;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		FString errorMsg = path + " is not exist";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

	FString JsonStr;
	if (FFileHelper::LoadFileToString(JsonStr, *(path)))
	{
		TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(JsonStr);
		TSharedPtr<FJsonObject> rRoot;

		if (FJsonSerializer::Deserialize(Reader, rRoot))
		{
			if (rRoot->HasField(TEXT("Frame")))
			{
				auto g_Ip = rRoot->GetIntegerField(TEXT("Frame"));
			}

			if (rRoot->HasField(TEXT("Weight")))
			{
				auto weights = rRoot->GetArrayField(TEXT("Weight"));
				int i = 0;
				for (auto& weight : weights)
				{
					if (weight.IsValid())
					{
						weights_map.Add(names[i], weight->AsNumber());
						//Weights_array.Add(weight->AsNumber());
						//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, weight->AsString());
					}
					else
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "weight is not valuid");
					}
					i += 1;

				}

			}
		}

	}
	else
	{
		FString errorMsg = "load file failed";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

}


// Called every frame
void AMyActor_test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


