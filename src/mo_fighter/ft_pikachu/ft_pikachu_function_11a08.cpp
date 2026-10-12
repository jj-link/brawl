#include <cm/cm_camera_controller.h>
#include <so/so_module_accesser.h>
#include <so/stageobject.h>

extern "C" float fn_98_11B2C(float value, float lower, float upper);

// The camera's rectangle at 0x148 is still opaque in the shared header.
static inline const Rect2D& cameraPositionBounds() {
    return *reinterpret_cast<const Rect2D*>(CameraController::getInstance()->_328);
}

#pragma always_inline on
extern "C" void fn_98_11A08(void*, soModuleAccesser* accesser) {
    soPostureModule& posture = *accesser->m_enumerationStart->m_postureModule;
    Vec3f position;
    position = posture.getPos();
    float right = cameraPositionBounds().m_right;
    float left = cameraPositionBounds().m_left;
    float x = fn_98_11B2C(position.m_x, left, right);
    float up = cameraPositionBounds().m_up;
    float down = cameraPositionBounds().m_down;
    float y = fn_98_11B2C(position.m_y, down, up);
    if (x != position.m_x || y != position.m_y) {
        position.m_x = x;
        position.m_y = y;
        posture.setPos(&position);
        posture.updateRotYLr();
        accesser->m_stageObject->updateNodeSRT();
    }
}
