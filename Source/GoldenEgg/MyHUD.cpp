// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "MyHUD.h"

void AMyHUD::DrawHUD()
{
    // 부모의 DrawHUD() 함수를 먼저 호출합니다.
    Super::DrawHUD();
    // 이제 필요한 것을 그리는 과정을 진행합니다.
    // 선을 그릴 수 있습니다.
    DrawLine(200, 300, 400, 500, FLinearColor::Blue);
    // 그리고 문자열도 그릴 수 있습니다!
    DrawText(TEXT("Unreal이 여러분을 환영합니다!"), FColor::White, 0, 0, hudFont, 1.0f, false);

    canvasSizeX = Canvas->SizeX;
    canvasSizeY = Canvas->SizeY;
}

void AMyHUD::DrawMessages()
{
    // 마지막부터 역으로 반복을 시작합니다.
    // 이렇게 해야 반복 중에 아이템을 삭제해도 문제가 생기지 않을 것입니다.
    for (int c = messages.Num() - 1; c >= 0; c--) {
        // 메시지를 출력할 올바른 장소에 배경 박스를 그립니다.
        float outputWidth, outputHeight, pad = 10.f;
        GetTextSize(messages[c].message, outputWidth, outputHeight, hudFont, 1.f);
        float messageH = outputHeight + 2.f * pad;
        float x = 0.f, y = c * messageH;

        // 배경을 검정색으로 합니다.
        DrawRect(FLinearColor::Black, x, y, canvasSizeX, messageH);

        // hudFont를 사용하여 메시지를 그립니다.
        DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);

        // 출력시간을 이전 프레임부터 지난 시간만큼 뺍니다.
        messages[c].time -= GetWorld()->GetDeltaSeconds();

        // 시간이 다 되었다면 삭제합니다.
        if (messages[c].time < 0) {
            messages.RemoveAt(c);
        }
    }
}

void AMyHUD::addMessage(Message msg)
{
    messages.Add(msg);
}
