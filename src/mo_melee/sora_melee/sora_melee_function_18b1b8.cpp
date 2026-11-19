#include <math.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

static inline Vec3f makePosition(float y, float x, float z) {
    Vec3f position;
    position.m_x = x;
    position.m_y = y;
    position.m_z = z;
    return position;
}

static inline void requestEffect(soModuleAccesser* accesser, float angle, const Vec2f& point) {
    Vec3f rotation(0.0f, 0.0f, -angle);
    Vec3f position = makePosition(point.m_y, point.m_x, 0.0f);
    int effect = accesser->getEffectModule().req(static_cast<EfID>(0x45), &position, &rotation, 1.0f, 0, -1);
    accesser->getWorkManageModule().setInt(effect, 0x20000001);
}

extern "C" void fn_27_18B1B8(void*, soModuleAccesser* accesser) {
    soDamageAttackerInfo* info = reinterpret_cast<soDamageAttackerInfo*>(accesser->getDamageModule().getDamageLog());
    int motionKinds[4][3] = {
        {0x9e, 0x9b, 0x98},
        {0x9f, 0x9c, 0x99},
        {0xa0, 0x9d, 0x9a},
        {0, 0, 0},
    };
    soMotionChangeParam param;
    param.m_kind = motionKinds[info->m_directTaskId][info->m_directSoKind];
    param.m_frame = 0.0f;
    param.m_rate = 1.0f;
    param._12 = 0;
    param._13 = 0;
    param._14 = 0;
    param._15 = 0;
    accesser->getMotionModule().changeMotionRequest(&param);

    float angle = 0.0f;
    if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
        Vec2f normal;
        Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
        angle = atan2f(normal.m_x, normal.m_y);
    }
    Vec2f point;
    Vec2f::copy(point, accesser->getGroundModule().getTouchPos(static_cast<grCollStatus::TouchMask>(8), 0));
    requestEffect(accesser, angle, point);
}
