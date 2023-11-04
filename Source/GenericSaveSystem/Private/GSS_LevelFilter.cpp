// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "GSS_LevelFilter.h"

FName UGSS_SaveFilter::TagNoTransform()
{
	const static FName Tag = {"!SaveTransform"};
	return Tag;
}

FName UGSS_SaveFilter::TagNoPhysics()
{
	const static FName Tag = {"!SavePhysics"};
	return Tag;
}

FName UGSS_SaveFilter::TagNoTags()
{
	const static FName Tag = {"!SaveTags"};
	return Tag;
}

FName UGSS_SaveFilter::TagSerializable()
{
	const static FName Tag = {"Serializable"};
	return Tag;
}

FName UGSS_SaveFilter::TagTransform()
{
	const static FName Tag = {"SaveTransform"};
	return Tag;
}
