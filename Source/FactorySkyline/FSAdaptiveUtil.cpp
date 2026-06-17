// ILikeBanas


#include "FSAdaptiveUtil.h"

void UFSAdaptiveUtil::Init()
{
}

UFGFactoryConnectionComponent* UFSAdaptiveUtil::GetConveyorConnection(AFGBuildableConveyorBase* Conveyor, int index)
{
	TSet<UActorComponent*> Set = Conveyor->GetComponents();
	for (UActorComponent* Component : Set) {
		UFGFactoryConnectionComponent* FactoryConnection = Cast<UFGFactoryConnectionComponent>(Component);
		if (FactoryConnection) {
			if (index == 0 && Component->GetName().Equals(TEXT("ConveyorAny0"))) return FactoryConnection;
			if (index == 1 && Component->GetName().Equals(TEXT("ConveyorAny1"))) return FactoryConnection;
		}
	}
	return nullptr;
}

TArray< FSplinePointData >* UFSAdaptiveUtil::GetConveyorBeltSplineData(AFGBuildableConveyorBelt* Conveyor)
{
	return &Conveyor->mSplineData;
}


void UFSAdaptiveUtil::CopyConveyorLiftAttribute(AFGBuildableConveyorLift* Source, AFGBuildableConveyorLift* Target)
{
	Target->mTopTransform = Source->mTopTransform;
	Target->mIsReversed = Source->mIsReversed;
}
