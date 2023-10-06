// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Notifies/PaperZDAnimNotify_Base.h"
#include "AnimSequences/PaperZDAnimSequence.h"

UPaperZDAnimNotify_Base::UPaperZDAnimNotify_Base(const FObjectInitializer& ObjectInitializer)
	: Super()
{
	Name = FName(TEXT("BaseNotify"));
	Color = FLinearColor::Red;
	
#if WITH_EDITORONLY_DATA
	bShouldFireInEditor = true;
#endif
}

UWorld* UPaperZDAnimNotify_Base::GetWorld() const
{
	return SequenceRenderComponent ? SequenceRenderComponent->GetWorld() : NULL;
}

FName UPaperZDAnimNotify_Base::GetDisplayName_Implementation() const
{
	return Name;
}

void UPaperZDAnimNotify_Base::TickNotify(float DeltaTime, float Playtime, float LastPlaybackTime, UPrimitiveComponent* AnimRenderComponent, UPaperZDAnimInstance* OwningInstance /* = nullptr */)
{
	SequenceRenderComponent = AnimRenderComponent;
}

UObject* UPaperZDAnimNotify_Base::GetContainingAsset() const
{
	UObject* ContainingAsset = GetTypedOuter<UPaperZDAnimSequence>();
	if (ContainingAsset == nullptr)
	{
		ContainingAsset = GetOutermost();
	}
	return ContainingAsset;
}
