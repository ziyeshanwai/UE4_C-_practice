// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFALOADJSON.h"


void UAIFALOADJSON::loadAIFAjson(FString rootpath, FString filename, TArray<float>& Weights_array)
{
	FString path = rootpath + filename;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		const FString errorMsg = path + "文件不存在.";
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
						// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, weight->AsString());
						//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, weight->AsString());
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
		const FString errorMsg = "加载文件失败.";
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, errorMsg);
		return;
	}

}


void UAIFALOADJSON::getJsonNames(int num, TArray<FString>& names_array)
{
	for (int i = 0; i < num; i++)
	{
		names_array.Add(FString::FromInt(i) + ".json");
	}
}

