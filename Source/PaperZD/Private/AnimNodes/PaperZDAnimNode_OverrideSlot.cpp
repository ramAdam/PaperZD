// Copyright 2017 ~ 2023 Critical Failure Studio Ltd. All rights reserved.

#include "AnimNodes/PaperZDAnimNode_OverrideSlot.h"

FPaperZDAnimNode_OverrideSlot::FPaperZDAnimNode_OverrideSlot()
{
	SlotName = TEXT("DefaultSlot");
	GroupName = TEXT("DefaultGroup");
}

void FPaperZDAnimNode_OverrideSlot::OnInitialize(const FPaperZDAnimationInitContext& InitContext)
{
	bOverride = false;
	Animation.Initialize(InitContext);
}

void FPaperZDAnimNode_OverrideSlot::OnUpdate(const FPaperZDAnimationUpdateContext& UpdateContext)
{
	//If there's an override, we need to make sure the weight of this update call is zero, to avoid any unwanted notify from triggering.
	bOverride = UpdateContext.AnimInstance->GetAnimationOverrideDataBySlot(SlotName, AnimSequencePtr, PlaybackTime);
	if (bOverride)
	{
		Animation.Update(UpdateContext.FractionalWeight(0.0f));
	}
	else
	{
		Animation.Update(UpdateContext);
	}
}

void FPaperZDAnimNode_OverrideSlot::OnEvaluate(FPaperZDAnimationPlaybackData& OutData)
{
	if (bOverride)
	{
		OutData.SetAnimation(AnimSequencePtr.Get(), PlaybackTime);
	}
	else
	{
		Animation.Evaluate(OutData);
	}
}
