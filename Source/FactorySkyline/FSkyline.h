// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "FGSubsystem.h"
#include "FGPlayerController.h"
#include "FGWorldSettings.h"
#include "FSBuilder.h"
#include "FSSelection.h"
#include "FSBuildableService.h"
#include "FSSelectService.h"
#include "FSAdaptiveUtil.h"
#include "UI/FGGameUI.h"
#include "UI/FGPopupWidget.h"
#include "UI/FSkylineUI.h"
#include "FGHUD.h"
#include "FSController.h"
#include "Operators/FSBuildableOperator.h"
#include "Subsystem/ModSubsystem.h"

#include "FSkyline.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSkyline, Log, All);


#define Log(msg, ...) UE_LOG(LogSkyline, Log, TEXT(msg), __VA_ARGS__)

/**
 * 
 */
UCLASS()
class FACTORYSKYLINE_API AFSkyline : public AModSubsystem, public IFGSaveInterface
{
	GENERATED_BODY()
public:
	
	void Init();

	UFUNCTION(BlueprintPure)
	static AFSkyline* Get(UObject* WorldContext);

	void InitFullSetup();

	virtual bool ShouldSave_Implementation() const override { return FSCtrl && FSCtrl->Etc ? !FSCtrl->Etc->GetBool("DontSaveAnything") : false; }


	UWorld* World = nullptr;
	AFGWorldSettings* WorldSettings = nullptr;
	AFGPlayerController* FGController = nullptr;
	UFGGameUI* GameUI = nullptr;
	AFGHUD* HUD = nullptr;

	bool IsFullLoaded = false;

	UPROPERTY()
	TObjectPtr<AFSBuilder> Builder = nullptr;

	UPROPERTY()
	TObjectPtr<UFSSelection> Select = nullptr;

	UPROPERTY()
	TObjectPtr<UFSkylineUI> SkylineUI = nullptr;

	UPROPERTY(SaveGame)
	TObjectPtr<AFSController> FSCtrl = nullptr;

	UPROPERTY()
	TObjectPtr<UFSOperatorFactory> OperatorFactory = nullptr;

	UPROPERTY()
	TObjectPtr<UFSSplineHologramFactory> SplineHologramFactory = nullptr;

	UPROPERTY()
	TObjectPtr<UFSBuildableService> BuildableService = nullptr;

	UPROPERTY()
	TObjectPtr<UFSConnectSelectService> ConnectSelectService = nullptr;

	UPROPERTY()
	TObjectPtr<UFSRectSelectService> RectSelectService = nullptr;

	UPROPERTY()
	TObjectPtr<UFSAdaptiveUtil> AdaptiveUtil = nullptr;

	void Connect(AFGBuildable* selfCA);

	
	/** Helper to spawn subsystems. */
	template< class C >
    void SpawnSubsystem( C*& out_spawnedSubsystem, TSubclassOf< AFGSubsystem > spawnClass, FName spawnName )
	{
		if( out_spawnedSubsystem )
		{
			UE_LOG( LogSkyline, Error, TEXT( "AFGWorldSettings::SpawnSubsystem failed for '%s', already spawned or loaded." ), *spawnName.ToString() );
			return;
		}

		if( !spawnClass )
		{
			UE_LOG( LogSkyline, Error, TEXT( "AFGWorldSettings::SpawnSubsystem failed for '%s', no class given." ), *spawnName.ToString() );
			return;
		}

		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.Name = spawnName;

		out_spawnedSubsystem = GetWorld()->SpawnActor< C >( spawnClass, spawnParams );
		check( out_spawnedSubsystem );
	}
private:
	template <class T>
	T* SpawnHiddenActor();


	
};
