#pragma once
#include "CoreMinimal.h"
#include "ETresWeaponForm.h"
#include "TresEquipDataBase.h"
#include "TresEquipValiableSetList.h"
#include "TresEquipKeybladeData.generated.h"

UCLASS(BlueprintType)
class TRESGAME_API UTresEquipKeybladeData : public UTresEquipDataBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ETresWeaponForm, FTresEquipValiableSetList> m_EquipMap;
    
public:
    UTresEquipKeybladeData();
};

