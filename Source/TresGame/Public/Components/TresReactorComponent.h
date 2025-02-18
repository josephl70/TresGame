#pragma once
#include "CoreMinimal.h"
#include "TresGimmickComponentBase.h"
#include "ETresReactorCommandID.h"
#include "UObject/NoExportTypes.h"
#include "TresReactorComponentInterface.h"
#include "TresCollShapeAssetUnit.h"
#include "TresReactorDoCommandSignatureDelegate.h"
#include "TresReactorComponent.generated.h"

class UBodySetup;
class AActor;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTresReactorComponent : public UTresGimmickComponentBase, public ITresReactorComponentInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    FColor m_ShapeColor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    uint32 m_bDrawBBox: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    FColor m_BBoxColor;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FTresCollShapeAssetUnit> m_CollisionShapesSrc;
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint32 m_bLimitRotRange: 1;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float m_RotRangeProp;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint32 m_bNeedRayCheck: 1;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    ETresReactorCommandID m_Command;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    AActor* m_CmdTargetActor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    uint32 m_bDisableTargetMarker: 1;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    uint32 m_bDisableCommandDisp: 1;
    
protected:
    UPROPERTY(DuplicateTransient, Transient)
    UBodySetup* m_pBodySetup;
    
public:
    UPROPERTY(BlueprintAssignable)
    FTresReactorDoCommandSignature OnReactorDoCommand;
    
    UTresReactorComponent();
    
    // Fix for true pure virtual functions not being implemented
};

