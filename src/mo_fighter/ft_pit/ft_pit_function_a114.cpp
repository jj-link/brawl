#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#pragma force_active on

struct PitInitializeObject;

extern "C" {
extern const char lbl_112_data_1F10[], lbl_112_data_27C4[];
extern const char lbl_112_data_26B0[], lbl_112_data_26DC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
int fn_27_14DB04(void*);
void fn_112_15ACC(PitInitializeObject*, int, int, int, float);
}

extern "C" bool fn_112_A114(Weapon* owner, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_112_data_1F10, lbl_112_data_27C4,
        short(1)));
    soResourceModule& resourceModule = accesser->getResourceModule();
    int taskId = accesser->m_stageObject->m_taskId;
    float scale = accesser->getPostureModule().getScale();
    fn_112_15ACC(reinterpret_cast<PitInitializeObject*>(owner), taskId,
        fn_27_14DB04(__dynamic_cast(
        resourceModule.getResourceIdAccesser(), 0, lbl_112_data_26B0,
        lbl_112_data_26DC, short(1))), fn_27_111364(fighter->getOwner()), scale);
    return true;
}
