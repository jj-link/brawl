#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>

struct LuigiInitializeObject;

extern "C" {
extern const char lbl_99_data_1940[], lbl_99_data_21F4[];
extern const char lbl_99_data_20E0[], lbl_99_data_210C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
int fn_27_14DB04(void*);
void fn_99_103D4(LuigiInitializeObject*, int, int, int, float);
}

extern "C" bool fn_99_8110(Weapon* owner, soModuleAccesser* accesser) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_99_data_1940, lbl_99_data_21F4,
        short(1)));
    soResourceModule& resourceModule = accesser->getResourceModule();
    int taskId = accesser->m_stageObject->m_taskId;
    float facing = accesser->getPostureModule().getLr();
    int ownerId = fn_27_111364(fighter->getOwner());
    int resource = fn_27_14DB04(__dynamic_cast(
        resourceModule.getResourceIdAccesser(), 0, lbl_99_data_20E0,
        lbl_99_data_210C, short(1)));
    fn_99_103D4(reinterpret_cast<LuigiInitializeObject*>(owner), taskId, resource, ownerId, facing);
    return true;
}
