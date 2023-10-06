// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#include "PaperZDAnimationComponent.h"
#include "PaperZDAnimInstance.h"
#include "Components/PrimitiveComponent.h"

// Sets default values for this component's properties
UPaperZDAnimationComponent::UPaperZDAnimationComponent()
	: AnimInstanceClass(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UPaperZDAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	//Create a fresh AnimInstance object
	CreateAnimInstance();
}

void UPaperZDAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Need to update the AnimInstance
	if (AnimInstance)
	{
		AnimInstance->Tick(DeltaTime);
	}
}

AActor* UPaperZDAnimationComponent::GetOwningActor() const
{
	return GetOwner();
}

UPrimitiveComponent* UPaperZDAnimationComponent::GetRenderComponent() const
{
	return Cast<UPrimitiveComponent>(RenderComponent.GetComponent(GetOwner()));
}

TSubclassOf<UPaperZDAnimInstance> UPaperZDAnimationComponent::GetSequencerAnimInstanceClass() const
{
	return AnimInstanceClass;
}

UPaperZDAnimInstance* UPaperZDAnimationComponent::GetSequencerAnimInstance()
{
	return GetOrCreateAnimInstance();
}

UPaperZDAnimInstance* UPaperZDAnimationComponent::GetOrCreateAnimInstance()
{
	if (!AnimInstance)
	{
		CreateAnimInstance();
	}

	return AnimInstance;
}

void UPaperZDAnimationComponent::CreateAnimInstance()
{
	if (AnimInstanceClass)
	{
		AnimInstance = NewObject<UPaperZDAnimInstance>(this, AnimInstanceClass);
		AnimInstance->Init(this);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No animation class defined on '%s', cannot create instance."), *GetName());
	}
}

void UPaperZDAnimationComponent::InitRenderComponent(UPrimitiveComponent* InRenderComponent)
{
	RenderComponent.PathToComponent = *InRenderComponent->GetPathName(GetOwner());
}

void UPaperZDAnimationComponent::SetAnimInstanceClass(TSubclassOf<UPaperZDAnimInstance> InAnimInstanceClass)
{
	AnimInstanceClass = InAnimInstanceClass;

	//Potentially re-create the anim instance, only if we already initialized the AnimInstance
	AnimInstance = nullptr;
	CreateAnimInstance();
}

void UPaperZDAnimationComponent::InitAnimInstanceClass(TSubclassOf<UPaperZDAnimInstance> InAnimInstanceClass)
{
	AnimInstanceClass = InAnimInstanceClass;
	AnimInstance = nullptr;
}
