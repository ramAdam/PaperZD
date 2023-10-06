// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Graphs/PaperZDAnimTransitionGraph.h"
#include "Graphs/Nodes/PaperZDTransitionGraphNode_Result.h"

UPaperZDAnimTransitionGraph::UPaperZDAnimTransitionGraph(const FObjectInitializer& ObjectInitializer)
	: Super()
{}

UPaperZDTransitionGraphNode_Result* UPaperZDAnimTransitionGraph::GetResultNode() const
{
	TArray<UPaperZDTransitionGraphNode_Result*> ResultNodes;
	GetNodesOfClass(ResultNodes);
	check(ResultNodes.Num() != 0); //Otherwise this is a malformed graph
	return ResultNodes[0];
}