// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Graphs/Nodes/PaperZDStateGraphNode_Root.h"
#include "Graphs/Nodes/Slate/SPaperZDStateGraphNode_Root.h"

UPaperZDStateGraphNode_Root::UPaperZDStateGraphNode_Root(const FObjectInitializer& ObjectInitializer)
	: Super()
{
}

void UPaperZDStateGraphNode_Root::AllocateDefaultPins()
{
	FCreatePinParams PinParams;
	CreatePin(EGPD_Output, TEXT("Transition"), TEXT(""), NULL, TEXT("Out"), PinParams);
}

TSharedPtr<SGraphNode> UPaperZDStateGraphNode_Root::CreateVisualWidget()
{ 
	return SNew(SPaperZDStateGraphNode_Root, this);
}

FString UPaperZDStateGraphNode_Root::GetNodeName() const
{
	return TEXT("Out");
}