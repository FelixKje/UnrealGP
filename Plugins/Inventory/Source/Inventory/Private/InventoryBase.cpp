﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryBase.h"



// Sets default values for this component's properties
UInventoryBase::UInventoryBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bDebug)
	{
		Debug();
	}
}

TArray<FItemStruct>& UInventoryBase::GetItems()
{
	return Items;
}

bool UInventoryBase::AddItem(const FItemStruct& NewItem)
{
	Items.Add(NewItem);
	OnInventoryChanged.Broadcast(NewItem);
	return true;
}

bool UInventoryBase::RemoveItem(const FItemStruct& Item)
{
	for(int i = 0; i < Items.Num(); ++i)
	{
		const FItemStruct ItemIndex = Items[i];
		if(ItemIndex.ItemPDA == Item.ItemPDA)
		{
			Items.Remove(ItemIndex);
			return true;
		}
	}
	return false;
}

FItemStruct UInventoryBase::CreateItem(const FItemStruct& Item)
{
	if (Item.ItemPDA)
	{
		return FItemStruct{Item.ItemPDA};
	}
	return FItemStruct{nullptr};
}

void UInventoryBase::Debug()
{
	for (const FItemStruct ItemIndex : GetItems())
	{
		PRINT(0,ItemIndex.ItemPDA->Text.ToString());
	}
}

