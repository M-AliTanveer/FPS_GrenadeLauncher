// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "MaulProtoPrecompiled.h"
#include "GameFramework/HUD.h"
#include "GrenadeProjectHUD.generated.h"

UCLASS()
class AGrenadeProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGrenadeProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

