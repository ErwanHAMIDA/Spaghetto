
#pragma once

#include "CoreMinimal.h"
#include "UMusicBossAction.h"
#include "FMusicBossEvent.generated.h"

USTRUCT(BlueprintType)
struct SPAGHETTO_API FMusicBossEvent
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    int32 BarIndex = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    int32 BeatIndex = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    bool IsLooping;

    UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = "Music")
    TObjectPtr<UMusicBossAction> Action;
};
