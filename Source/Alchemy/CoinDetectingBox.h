// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"
#include "CoinDetectingBox.generated.h"

UCLASS()
class ALCHEMY_API ACoinDetectingBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinDetectingBox();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;
	UPROPERTY(VisibleAnyWhere)
	int numCoins;
	UPROPERTY(VisibleAnyWhere)
	UBoxComponent* box;
	UPROPERTY(VisibleAnyWhere)
	USpotLightComponent* light;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int NumCoinsInBox();

};
