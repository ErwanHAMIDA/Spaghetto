
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimerManager.h"
#include "UMusicBossAction.generated.h"

UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class SPAGHETTO_API UMusicBossAction : public UObject
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Music")
    void Execute(AActor* Boss);

    UFUNCTION(BlueprintCallable, Category = "Music")
    void StartTimedAction(AActor* Boss, float Duration);

    UFUNCTION(BlueprintImplementableEvent, Category = "Music")
    void ReceiveActionUpdate(AActor* Boss, float Alpha);

    UFUNCTION(BlueprintImplementableEvent, Category = "Music")
    void ReceiveActionFinished(AActor* Boss);

protected:

    void UpdateTimedAction();

    TWeakObjectPtr<AActor> ActiveBoss;

    FTimerHandle ActionTimerHandle;

    float ActionStartTime = 0.0f;
    float ActionDuration = 0.0f;
    float UpdateInterval = 0.016f;
};
