// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "PaperZDCharacter.h"
#include "PaperZDAnimationComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperZDCustomVersion.h"
#include "PaperZDAnimInstance.h"

#if WITH_EDITOR
#include "PaperZDAnimBP.h"
#endif

APaperZDCharacter::APaperZDCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AnimationComponent = CreateDefaultSubobject<UPaperZDAnimationComponent>(TEXT("Animation"));
	AnimationComponent->InitRenderComponent(GetSprite());
}

void APaperZDCharacter::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	//Backwards compatibility, after the AnimBlueprint rework the character became a "wrapper" class for the 
	//animation component, hence we must make sure the AnimInstanceClass value gets initialized correctly
	const int32 ZDVersion = GetLinkerCustomVersion(FPaperZDCustomVersion::GUID);
	if (ZDVersion < FPaperZDCustomVersion::AnimBlueprintRework)
	{
		//We cannot use the AnimInstanceClass variable directly because it's pointing to a class that got consigned to oblivion.
		//The new compiler has created a brand new generated class at this point and the only way to obtain it is to query the Animation Blueprint directly.
 		if (AnimationBlueprint_DEPRECATED)
 		{
			TSubclassOf<UPaperZDAnimInstance> AnimInstanceClass = AnimationBlueprint_DEPRECATED->GeneratedClass.Get();
			AnimationComponent->InitAnimInstanceClass(AnimInstanceClass);
 		}
	}
#endif
}

void APaperZDCharacter::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	Ar.UsingCustomVersion(FPaperZDCustomVersion::GUID);
}

TSubclassOf<UPaperZDAnimInstance> APaperZDCharacter::GetSequencerAnimInstanceClass() const
{
	return AnimationComponent->GetSequencerAnimInstanceClass();
}

UPaperZDAnimInstance* APaperZDCharacter::GetSequencerAnimInstance()
{
	return AnimationComponent->GetSequencerAnimInstance();
}

UPaperZDAnimInstance* APaperZDCharacter::GetAnimInstance() const
{
	return AnimationComponent->GetAnimInstance();
}
