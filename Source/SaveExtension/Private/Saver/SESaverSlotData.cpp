// Fill out your copyright notice in the Description page of Project Settings.


#include "Saver/SESaverSlotData.h"

void USESaverSlotData::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar << DataRecords;

}
