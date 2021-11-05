// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingRangeTarget.h"

#include "ShootingRangeGameState.h"
#include "ShootingRangePlayerState.h"
#include "ShootingRangeProjectile.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShootingRangeTarget::AShootingRangeTarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShootingRangeTarget::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShootingRangeTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShootingRangeTarget::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	check(GEngine);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow,TEXT("Overlap"));
	OtherActor->Destroy();
}

void AShootingRangeTarget::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
                                     bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
                                     const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//打在上面的是子弹
	if (Other->GetClass()->IsChildOf(AShootingRangeProjectile::StaticClass()))
	{
		//获取当前玩家控制器
		APlayerController* PController=UGameplayStatics::GetPlayerController(GetWorld(),0);
		if(PController!=nullptr){
			UINT Score=PController->PlayerState->GetScore();
			PController->PlayerState->SetScore(Score+1);
			check(GEngine);
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Black,FString("Score:")+FString::FromInt(Score+1));
		}
	}
}
