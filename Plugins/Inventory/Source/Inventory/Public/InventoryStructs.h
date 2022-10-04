#pragma once
#include "ItemPDABase.h"

#include "InventoryStructs.generated.h"
USTRUCT(BlueprintType)
struct FItemStruct
{
	GENERATED_BODY()

	FItemStruct(): ItemPDA(nullptr), Durability(0), Id(FGuid::NewGuid())
	{
	}

	FItemStruct(UItemPDABase* ItemPda): ItemPDA(ItemPda), Durability(100), Id(FGuid::NewGuid())
	{
		
	}

	FItemStruct(UItemPDABase* ItemPda, float Durability) : ItemPDA(ItemPda), Durability(Durability), Id(FGuid::NewGuid())
	{
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* ItemPDA;

	UPROPERTY(BlueprintReadWrite)
	float Durability;

	UPROPERTY(VisibleAnywhere)
	FGuid Id;

	bool operator ==(const FItemStruct& other) const
	{
		return this->Id == other.Id && ItemPDA;
	}
	
	bool operator !=(const FItemStruct& other) const
	{
		return this->Id != other.Id && ItemPDA;
	}

	bool IsValid() const;
};
