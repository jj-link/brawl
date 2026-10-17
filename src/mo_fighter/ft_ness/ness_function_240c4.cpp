#include <so/so_module_accesser.h>
#include <so/stageobject.h>

// wnNessYoyoHeadStatusUniqProcessShot::execFixPos
// Correct each contacted axis before updating the stage object's transform.
extern "C" void fn_101_240C4(void* /*uniqProcess*/, soModuleAccesser* accesser) {
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soGroundModule* ground = modules->m_groundModule;
    soPostureModule* posture = modules->m_postureModule;

    Vec3f fixedPos = posture->getPos();
    Vec3f groundPos = ground->getCorrectPos(0);
    if (ground->isTouch(grCollStatus::TOUCH_MASK_UP | grCollStatus::TOUCH_MASK_DOWN, 0)) {
        fixedPos.m_y = groundPos.m_y;
    }
    if (ground->isTouch(grCollStatus::TOUCH_MASK_LEFT | grCollStatus::TOUCH_MASK_RIGHT, 0)) {
        fixedPos.m_x = groundPos.m_x;
    }
    posture->setPos(&fixedPos);

    StageObject* stageObject = accesser->m_stageObject;
    stageObject->updateNodeSRT();
}
