// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Sequencer/IPaperZDSequencerSource.h"

TSubclassOf<UPaperZDAnimInstance> IPaperZDSequencerSource::GetSequencerAnimInstanceClass() const
{
	return nullptr;
}

UPaperZDAnimInstance* IPaperZDSequencerSource::GetSequencerAnimInstance()
{
	return nullptr;
}
