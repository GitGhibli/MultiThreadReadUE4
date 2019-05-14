// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class MultiThreadReadUE4EditorTarget : TargetRules
{
	public MultiThreadReadUE4EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "MultiThreadReadUE4" } );
	}
}
