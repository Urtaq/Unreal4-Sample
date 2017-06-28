// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

struct Message
{
    FString message;
    float time;
    FColor color;
    Message()
    {
        // 기본 값을 설정합니다.
        time = 5.f;
        color = FColor::White;
    }

    Message(FString iMessage, float iTime, FColor iColor)
    {
        message = iMessage;
        time = iTime;
        color = iColor;
    }
};

/**
 * 
 */
UCLASS()
class GOLDENEGG_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
    // 폰트는 HUD에서 문자열을 표시하는데 사용됩니다.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
    UFont *hudFont;

    // 이 함수를 추가해 HUD를 그릴 수 있도록 합시다.
    virtual void DrawHUD() override;

    // 출력할 메시지의 배열입니다.
    TArray<Message> messages;

    int32 canvasSizeX;
    int32 canvasSizeY;
    void DrawMessages();

    // 출력할 메시지를 추가할 수 있는 함수입니다.
    void addMessage(Message msg);
	
};
