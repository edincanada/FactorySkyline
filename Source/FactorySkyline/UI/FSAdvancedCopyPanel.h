// ILikeBanas

#pragma once

#include "CoreMinimal.h"
#include "FactorySkyline/UI/FSFoldWidgetBase.h"
#include "FactorySkyline/FSDesign.h"
#include "Blueprint/UserWidget.h"
#include "Buildables/FGBuildable.h"
#include "FSAdvancedCopyPanel.generated.h"

/**
 * 
 */
UCLASS()
class FACTORYSKYLINE_API UFSAdvancedCopyPanel : public UUserWidget
{
	GENERATED_BODY()
public:
	UFSAdvancedCopyPanel(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> BuildButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> SetRepeatButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> ClipboardButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> SetCircleButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UFSFoldWidgetBase> FoldPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UTextBlock> BuildStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> BuildPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> SetRepeatPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> ClipboardPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCanvasPanel> SetCirclePanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> VectorX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> VectorY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> VectorZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> RotationX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> RotationY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> RotationZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> RotationW;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UEditableText> RotationAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> VectorXBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> VectorYBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> VectorZBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> RotationXBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> RotationYBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> RotationZBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> RotationWBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> RotationAngleBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCheckBox> CheckBoxVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCheckBox> CheckBoxRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCheckBox> CheckBoxCircle;

	TWeakObjectPtr<AFGBuildable> CircleCenter = nullptr;
	UFSDesign* Design = nullptr;

	UFUNCTION()
	void onCheckBoxChanged(bool IsChecked);
	UFUNCTION()
	void onCheckBoxChangedVector(bool IsChecked);
	UFUNCTION()
	void onCheckBoxChangedRotation(bool IsChecked);
	UFUNCTION()
	void onCheckBoxChangedCircle(bool IsChecked);

	UFUNCTION()
	void OnEditableTextCommittedVectorX(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedVectorY(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedVectorZ(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedRotationX(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedRotationY(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedRotationZ(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedRotationW(const FText& Text, ETextCommit::Type CommitMethod);
	UFUNCTION()
	void OnEditableTextCommittedRotationAngle(const FText& Text, ETextCommit::Type CommitMethod);

	FString Format(double Value);

	UFUNCTION()
	void onBuild();

	UFUNCTION()
	void onSetRepeat();

	UFUNCTION()
	void onSetCircle();

	UFUNCTION()
	void onClipboard();

	void SetCircleFeedback();
	void UpdateCircle();

	void Init();
	void Load(UFSDesign* Design);

	void UpdateTransform();
	FTransform GetTransform();
	void SetTransform(const FTransform& Transform);

	void Fold();
	void Expand();
};
