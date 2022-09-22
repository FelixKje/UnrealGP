// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GP_21Interface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UGP_21Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORY_API IGP_21Interface
{
	GENERATED_IINTERFACE_BODY();

	virtual void VoidFunction();
public:
};
