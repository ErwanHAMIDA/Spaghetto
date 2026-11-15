
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FMusicBossEvent.h"
#include "BossActor.generated.h"

UCLASS()
class SPAGHETTO_API ABossActor : public AActor
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    TArray<FMusicBossEvent> MusicEvents;

    ABossActor();

};
