// Copyright 2017 ~ 2022 Critical Failure Studio Ltd. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IPaperZDAnimInstanceManager.h"
#include "Sequencer/IPaperZDSequencerSource.h"
#include "PaperZDAnimationComponent.generated.h"

class UPrimitiveComponent;
class UPaperZDAnimInstance;

/**
 * Provides an interface for running an Animation Blueprint on any actor.
 */
UCLASS( ClassGroup=(PaperZD), meta=(BlueprintSpawnableComponent, DisplayName = "PaperZD Animation") )
class PAPERZD_API UPaperZDAnimationComponent : public UActorComponent, public IPaperZDAnimInstanceManager, public IPaperZDSequencerSource
{
	GENERATED_BODY()

	/* Animation blueprint class to use. */
	UPROPERTY(EditAnywhere, Category = "PaperZD")
	TSubclassOf<UPaperZDAnimInstance> AnimInstanceClass;

	/* Render component to update when using the animation blueprints. */
	UPROPERTY(EditAnywhere, Category = "PaperZD", meta = (AllowAnyComponent, UseComponentPicker, AllowedClasses = "PrimitiveComponent"))
	FComponentReference RenderComponent;

	/* The animation instance used for managing the animation. */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "PaperZD", meta = (AllowPrivateAccess = " true"))
	UPaperZDAnimInstance* AnimInstance;

public:	
	// Sets default values for this component's properties
	UPaperZDAnimationComponent();

	//getter
	FORCEINLINE UPaperZDAnimInstance* GetAnimInstance() const { return AnimInstance; }
	FORCEINLINE TSubclassOf<UPaperZDAnimInstance> GetAnimInstanceClass() const { return AnimInstanceClass; }

	//~ Begin UActorComponent Interface
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//~ End UActorComponent Interface

	//~ Begin IPaperZDAnimInstanceManager Interface
	virtual AActor* GetOwningActor() const override;
	virtual UPrimitiveComponent* GetRenderComponent() const override;
	//~ End IPaperZDAnimInstanceManager Interface

	//~ Begin IPaperZDSequencerSource Interface
	virtual TSubclassOf<UPaperZDAnimInstance> GetSequencerAnimInstanceClass() const override;
	virtual UPaperZDAnimInstance* GetSequencerAnimInstance() override;
	//~ End IPaperZDSequencerSource Interface

	/* Getter for the anim instance which Lazy Loads it if needed. */
	UPaperZDAnimInstance* GetOrCreateAnimInstance();

	/* Sets the render component to use before the AnimInstance has been created, use it on construction to set up the values for initialization. */
	void InitRenderComponent(UPrimitiveComponent* InRenderComponent);

	/* Sets the AnimInstanceClass to use, replacing any AnimInstane that could already be running. */
	UFUNCTION(BlueprintCallable, Category = "PaperZD")
		void SetAnimInstanceClass(TSubclassOf<UPaperZDAnimInstance> InAnimInstanceClass);

	/* Sets the AnimInstanceClass directly, not triggering any event nor recreating the AnimInstance. Used for initializing. */
	void InitAnimInstanceClass(TSubclassOf<UPaperZDAnimInstance> InAnimInstanceClass);

private:
	/* Attempts to create a fresh AnimInstance object. */
	void CreateAnimInstance();
};
