// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "IPaperZDAnimInstanceManager.h"
#include "GameFramework/Actor.h"

AActor* IPaperZDAnimInstanceManager::GetOwningActor() const
{
	return nullptr;
}

UPrimitiveComponent* IPaperZDAnimInstanceManager::GetRenderComponent() const
{
	return nullptr;
}

UWorld* IPaperZDAnimInstanceManager::OnGetWorld() const
{
	return GetOwningActor() ? GetOwningActor()->GetWorld() : nullptr;
}
