// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "Components/CheckBox.h"
#include "Blueprint/UserWidget.h"
#include "FSFoldWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class FACTORYSKYLINE_API UFSFoldWidgetBase : public UUserWidget
{
	GENERATED_BODY()
public:
	UFSFoldWidgetBase(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCheckBox> FoldBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UUserWidget> Dark;

};
