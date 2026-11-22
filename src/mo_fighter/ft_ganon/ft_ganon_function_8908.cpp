#include <ft/fighter.h>
#include <wn/weapon.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_109_data_1894[0x8];
extern unsigned char lbl_109_data_2034[0x8];
extern unsigned char lbl_109_data_2060[0x8];
extern unsigned char lbl_109_data_2148[0x8];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
int fn_27_14DB04(void*);
void fn_109_112A8(void*, int, int, int, Vec3f*, float);
}

extern "C" bool fn_109_8908(Weapon* self, soModuleAccesser* accesser) {
    int taskId;
    soPostureModule& posture = accesser->getPostureModule();
    Fighter* fighter = (Fighter*)__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_109_data_1894, lbl_109_data_2148,
        short(1));
    soResourceModule& resourceModule = accesser->getResourceModule();
    taskId = accesser->m_stageObject->m_taskId;
    float lr = posture.getLr();
    Vec3f pos = posture.getPos();
    fn_109_112A8(self, taskId, fn_27_14DB04(__dynamic_cast(
        resourceModule.getResourceIdAccesser(), 0, lbl_109_data_2034,
        lbl_109_data_2060, short(1))), fn_27_111364(fighter->getOwner()), &pos, lr);
    taskId = (int)&accesser->getWorkManageModule();
    int id = self->getTaskId();
    ((soWorkManageModule*)taskId)->setInt(id, 0x20000000);
    return true;
}
