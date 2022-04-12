// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABSection.generated.h"

UCLASS()
class ARENABATTLE_API AABSection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABSection();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*> GateMeshes;

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

};
