// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "Graphs/Nodes/PaperZDAnimGraphNode_Sink.h"
#include "Editors/Util/PaperZDEditorSettings.h"

#define LOCTEXT_NAMESPACE "ZDNodes"

UPaperZDAnimGraphNode_Sink::UPaperZDAnimGraphNode_Sink()
	: Super()
{}

FLinearColor UPaperZDAnimGraphNode_Sink::GetNodeTitleColor() const
{
	return GetDefault<UPaperZDEditorSettings>()->ResultNodeTitleColor;
}

FText UPaperZDAnimGraphNode_Sink::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	FText DefaultTitle = LOCTEXT("PaperZDAnimGraphNodeSink_Title", "Output Animation");

	if (TitleType != ENodeTitleType::FullTitle)
	{
		return DefaultTitle;
	}
	else
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("NodeTitle"), DefaultTitle);
		Args.Add(TEXT("Name"), FText::FromString(GetOuter()->GetName()));

		return FText::Format(LOCTEXT("AnimGraphNodeRoot_TitleNamed", "{NodeTitle}\n{Name}"), Args);
	}
}
#undef LOCTEXT_NAMESPACE
