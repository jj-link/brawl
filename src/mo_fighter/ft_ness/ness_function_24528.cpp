#include <so/so_module_accesser.h>
#include <so/stageobject.h>

// Pulls the fighter back onto the surface it is touching and refreshes the
// stage object's node transform afterwards.
extern "C" void fn_101_24528(void* /*unused*/, soModuleAccesser* accesser) {
    soGroundModule* ground = &accesser->getGroundModule();
    soPostureModule* posture = &accesser->getPostureModule();
    Vec3f pos = posture->getPos();
    Vec3f correct = ground->getCorrectPos(0);
    if (ground->isTouch(grCollStatus::TOUCH_MASK_UP | grCollStatus::TOUCH_MASK_DOWN, 0)) {
        pos.m_y = correct.m_y;
    }
    if (ground->isTouch(grCollStatus::TOUCH_MASK_LEFT | grCollStatus::TOUCH_MASK_RIGHT, 0)) {
        pos.m_x = correct.m_x;
    }
    posture->setPos(&pos);
    accesser->m_stageObject->updateNodeSRT();
}
