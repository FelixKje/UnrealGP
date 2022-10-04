// Fill out your copyright notice in the Description page of Project Settings.


#include "GP_21Interface.h"

#include "InventoryBase.h"


// Add default functionality here for any IGP_21Interface functions that are not pure virtual.
void IGP_21Interface::PrintSomething()
{
	PRINT(10, FColor::Blue,TextToPrint())
}
