// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

namespace UnrealBuildTool.Rules
{

	public class GenericSaveSystem : ModuleRules
	{
		public GenericSaveSystem(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;

			PublicDependencyModuleNames.AddRange(new string[]
			{
			"Core",
			"Engine",
			"Foliage",
			"AIModule",
			"CoreUObject",
			"DeveloperSettings",
			"ImageWrapper",
			"NavigationSystem"
			});
		}
	}

}
