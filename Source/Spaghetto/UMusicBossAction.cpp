
#include "UMusicBossAction.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"

void UMusicBossAction::Execute_Implementation(AActor* Boss)
{
}

void UMusicBossAction::StartTimedAction(AActor* Boss, float Duration)
{
    if (!IsValid(Boss))
    {
        return;
    }

    UWorld* World = Boss->GetWorld();

    if (!World)
    {
        return;
    }

    // Nettoie une éventuelle exécution précédente
    World->GetTimerManager().ClearTimer(ActionTimerHandle);

    ActiveBoss = Boss;
    ActionDuration = FMath::Max(Duration, 0.01f);
    ActionStartTime = World->GetTimeSeconds();

    World->GetTimerManager().SetTimer(
        ActionTimerHandle,
        this,
        &UMusicBossAction::UpdateTimedAction,
        UpdateInterval,
        true
    );
}

void UMusicBossAction::UpdateTimedAction()
{
    AActor* Boss = ActiveBoss.Get();

    if (!IsValid(Boss))
    {
        return;
    }

    UWorld* World = Boss->GetWorld();

    if (!World)
    {
        return;
    }

    const float ElapsedTime =
        World->GetTimeSeconds() - ActionStartTime;

    const float Alpha =
        FMath::Clamp(ElapsedTime / ActionDuration, 0.0f, 1.0f);

    ReceiveActionUpdate(Boss, Alpha);

    if (Alpha >= 1.0f)
    {
        World->GetTimerManager().ClearTimer(ActionTimerHandle);

        ActiveBoss.Reset();

        ReceiveActionFinished(Boss);
    }
}
