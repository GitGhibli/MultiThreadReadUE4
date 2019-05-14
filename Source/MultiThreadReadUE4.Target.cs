// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class MultiThreadReadUE4Target : TargetRules
{
	public MultiThreadReadUE4Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "MultiThreadReadUE4" } );
	}
}
