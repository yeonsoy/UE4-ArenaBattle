// Fill out your copyright notice in the Description page of Project Settings.


#include "ABWeapon.h"

// Sets default values
AABWeapon::AABWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
	RootComponent = Weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT("/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	if (SK_WEAPON.Succeeded())
	{
		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	}

	Weapon->SetCollisionProfileName(TEXT("NoCollision"));

	AttackRange = 150.0f;
	AttackDamageMin = -2.5f;
	AttackDamageMax = 10.0f;
	AttackModifierMin = 0.85f;
	AttackModifierMax = 1.25f;
}

float AABWeapon::GetAttackRange() const
{
	return AttackRange;
}

float AABWeapon::GetAttackDamage() const
{
	return AttackDamage;
}

float AABWeapon::GetAttackModifier() const
{
	return AttackModifier;
}

void AABWeapon::BeginPlay()
{
	Super::BeginPlay();

	AttackDamage = FMath::RandRange(AttackDamageMin, AttackDamageMax);
	AttackModifier = FMath::RandRange(AttackModifierMin, AttackModifierMax);
	ABLOG(Warning, TEXT("Weapon Damage : %f, Modifier : %f"), AttackDamage, AttackModifier);
}