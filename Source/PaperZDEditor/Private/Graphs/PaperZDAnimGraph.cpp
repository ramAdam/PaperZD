// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Graphs/PaperZDAnimGraph.h"
#include "Graphs/PaperZDAnimGraphSchema_Transitional.h"
#include "PaperZDAnimBP.h"

//////////////////////////////////////////////////////////////////////////
//// PaperZD Anim Graph
//////////////////////////////////////////////////////////////////////////
UPaperZDAnimGraph::UPaperZDAnimGraph(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}

UPaperZDAnimBP* UPaperZDAnimGraph::GetAnimBP() const
{
	return CastChecked<UPaperZDAnimBP>(GetOuter());
}

bool UPaperZDAnimGraph::IsTransitionalGraph() const
{
	return GetSchema()->GetClass()->IsChildOf(UPaperZDAnimGraphSchema_Transitional::StaticClass());
}
