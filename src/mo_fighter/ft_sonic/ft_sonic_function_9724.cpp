#include <ft/fighter.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_123_data_1984[], lbl_123_data_2238[], lbl_123_data_2124[], lbl_123_data_2150[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_123_90FC(Vec2f*, const Vec2f*);
int fn_27_111364(ftOwner*);
int fn_27_14DB04(void*);
void fn_123_16960(void*, int, int, int, Vec2f*, float, int, void*);
}

extern "C" bool fn_123_9724(void* self, soModuleAccesser* accesser) {
    int task;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(accesser->m_stageObject, 0x3c, lbl_123_data_1984, lbl_123_data_2238, short(1)));
    Vec3f position = accesser->getPostureModule().getPos();
    Vec2f pos;
    fn_123_90FC(&pos, (Vec2f*)&position);
    soSituationModule& situation = accesser->getSituationModule();
    soPostureModule& posture = accesser->getPostureModule();
    soResourceModule& resource = accesser->getResourceModule();
    task = accesser->m_stageObject->m_taskId;
    fn_123_16960(self, task, fn_27_14DB04(__dynamic_cast(resource.getResourceIdAccesser(), 0, lbl_123_data_2124, lbl_123_data_2150, short(1))), fn_27_111364(fighter->getOwner()), &pos, posture.getLr(), situation.getKind(), soValueAccesser::getConstantIndefinite(accesser, 0xA802, 0));
    return true;
}