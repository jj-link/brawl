#include <wn/weapon.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>
#include <ft/fighter.h>

struct NessThunderInitializationOwner;

extern "C" {
extern const unsigned char lbl_101_data_3AB4[], lbl_101_data_4330[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_101_18EF4(NessThunderInitializationOwner*, unsigned int, int, const Vec3f*, float);
}

// Ness article activation callback (kind 2): resolves the owning Fighter,
// spawns the kind's thunder activation through fn_101_18EF4 with the
// model node position and facing, then links node 6 to the weapon's task.
extern "C" bool fn_101_C5C4(Weapon* owner, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(&accesser->getStageObject(), 0x3c,
        lbl_101_data_3AB4, lbl_101_data_4330, static_cast<short>(1)));
    Vec3f position = accesser->getModelModule().getNodeGlobalPosition(0x2A, false);
    float lr = accesser->getPostureModule().getLr();
    taskId = fighter->m_taskId;
    int ownerId = fn_27_111364(fighter->getOwner());
    fn_101_18EF4(reinterpret_cast<NessThunderInitializationOwner*>(owner), taskId, ownerId, &position, lr);
    accesser->getLinkModule().link(6, owner->m_taskId);
    return true;
}
