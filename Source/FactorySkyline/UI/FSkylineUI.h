// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "FactorySkyline/FSDesign.h"
#include "FactorySkyline/FSMenuItem.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "FactorySkyline/UI/FSLogoWidget.h"
#include "FactorySkyline/UI/FSOperatingWidget.h"
#include "FactorySkyline/UI/FSKeyMappingWidget.h"
#include "FactorySkyline/UI/FSCompletionWidget.h"
#include "FactorySkyline/UI/FSRepeatWidget.h"
#include "FactorySkyline/UI/FSSelectRect.h"
#include "FactorySkyline/UI/FSKeySettingsWidget.h"
#include "FactorySkyline/UI/FSInventoryWidget.h"
#include "FactorySkyline/UI/FSResourceIcon.h"
#include "Delegates/DelegateCombinations.h"

#include "FSkylineUI.generated.h"

/**
 * 
 */
UCLASS()
class FACTORYSKYLINE_API UFSkylineUI : public UUserWidget
{
	GENERATED_BODY()
public:

	UFSkylineUI(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> RootPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> RepeatBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> OperatingHelper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> MessageBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> ItemBox;

	UPROPERTY()
	TObjectPtr<UFSGettingStartMenu> GettingStart;

	UPROPERTY()
	TObjectPtr<UFSOperatingWidget> OperatingWidget;

	UPROPERTY()
	TArray<TObjectPtr<UFSMenuEntryBase>> EntryRecycle;

	UPROPERTY()
	TArray<TObjectPtr<UFSMenuWidget>> WidgetRecycle;

	UPROPERTY()
	TArray<TObjectPtr<UFSResourceIcon>> ResourceIcon;

	UPROPERTY()
	TObjectPtr<UFSLogoWidget> Logo;
	UCanvasPanelSlot* LogoSlot;

	UPROPERTY()
	TObjectPtr<UFSCompletionWidget> CompletionWidget;

	UPROPERTY()
	TObjectPtr<UFSRepeatWidget> RepeatWidget;

	UPROPERTY()
	TObjectPtr<UFSSelectRect> SelectRect;

	UPROPERTY()
	TObjectPtr<UFSKeySettingsWidget> KeySettingsWidget;

	UPROPERTY()
	TObjectPtr<UFSInventoryWidget> InventoryWidget;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> PressCtrlMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> HoldCtrlMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SelectScrollMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SelectMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SelectAnchorMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> ExitMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> CopyScrollMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> CopyMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SetRepeatMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SetAnchorMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> SetCircleCenterMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> GotoBuildMapping;

	UPROPERTY()
	TObjectPtr<UFSKeyMappingWidget> BackToSelectMapping;


	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);
	
	void FSMouseDown(UFSButtonWidget* ButtonWidget, const FPointerEvent& InMouseEvent);
	bool FSMouseUp(UFSButtonWidget* ButtonWidget, const FPointerEvent& InMouseEvent);
	void FSMouseMove(const FPointerEvent& InMouseEvent);
	void FSMouseMove(UFSButtonWidget* ButtonWidget, const FPointerEvent& InMouseEvent);
	void FSMouseMove(UFSMenuWidget* MenuWidget, const FPointerEvent& InMouseEvent);
	void FSMouseMove(UFSInventoryWidget* MenuWidget, const FPointerEvent& InMouseEvent);
	void FSMouseLeave(UFSMenuWidget* MenuWidget, const FPointerEvent& InMouseEvent);
	void FSMouseLeave(UFSInventoryWidget* MenuWidget, const FPointerEvent& InMouseEvent);

	bool Turtioul;
	bool IsActive;
	bool IsMouseCursorOnUI;

	UFSDesignMenu* DesignRoot = nullptr;
	UFSDesignMenu* LastFold = nullptr;

	bool Init(UWorld* World);

	void OpenMenu();
	void HideMenu();

	void FinishTurtioul();
	void ShowDesign();
	void FoldDesign();
	void FoldCurrent();
	void ExpandStart();
	void UnexpandStart(bool RestoreDesign);

	void SetHighLightMapping(UFSKeyMappingWidget* Mapping);
	void RestoreHighLightMapping();

	void ResetHighLight();

	UFSKeyMappingWidget* AddKeyMappingHelper(const FText& Title, const FText& Key);

	UFSDesignMenu* FindLastDesignItem();

	FKey LastKeyMouseDown;
	UFSButtonWidget* LastButtonMouseDown = nullptr;
	UFSButtonWidget* CurrentHighLightButton = nullptr;
	UFSKeyMappingWidget* CurrentHighLightMapping = nullptr;
};
