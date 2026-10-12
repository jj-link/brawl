#include <ft/fighter.h>

extern "C" {
extern const char lbl_101_data_3AB4[], lbl_101_data_4330[];
extern const float lbl_101_rodata_18;
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(ftOwner*);
void fn_101_2368C(void*, unsigned int, unsigned int, int, float, const Vec3f*, int);
}

// Resolve the fighter and its model position before forwarding the request.
extern "C" bool fn_101_CB28(void* request, soModuleAccesser* accesser) {
    unsigned int taskId;
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        &accesser->getStageObject(), 0x3C, lbl_101_data_3AB4, lbl_101_data_4330, 1));
    int normalDirection = 1;
    Vec3f position = accesser->getModelModule().getNodeGlobalPosition(0x42, false);
    float direction = accesser->getPostureModule().getLr();
    if (accesser->getStatusModule().getStatusKind() == 0x2D) {
        direction *= lbl_101_rodata_18;
        normalDirection = 0;
    }
    soResourceModule* resource = &accesser->getResourceModule();
    taskId = fighter->m_taskId;
    fn_101_2368C(request,
        taskId,
        resource->getResourceIdAccesser()->getEtcResId(),
        fn_27_111364(fighter->getOwner()), direction, &position, normalDirection);
    return true;
}
