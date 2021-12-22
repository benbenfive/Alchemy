// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinDetectingBox.h"
#include "MyActor.h"
#include <string>
#include "Containers/UnrealString.h"
// Sets default values
ACoinDetectingBox::ACoinDetectingBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	VisualMesh->BodyInstance.SetCollisionProfileName(TEXT("Overlap"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StaticMeshes/coin.coin"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void ACoinDetectingBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinDetectingBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->numCoins = this->NumCoinsInBox();

}

int ACoinDetectingBox::NumCoinsInBox()
{
	int coins = 0;
	TArray<AActor*> result;
	AActor::GetOverlappingActors(result, AMyActor::StaticClass());
	for (AActor* actor : result) {
		coins++;
	}
	FString s = FString::FromInt(coins);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, s);

	return coins;
}

