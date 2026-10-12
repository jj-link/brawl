#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_98_rodata_88[];
void fn_8003DBA8(Vec2f*);
}

#pragma always_inline on
#pragma inline_depth(8)
extern "C" void fn_98_1187C(void*, soModuleAccesser* accesser) {
    const float* constants = lbl_98_rodata_88;
    const soModuleEnumeration& modules = *accesser->m_enumerationStart;
    soGroundModule& ground = *modules.m_groundModule;
    if (modules.m_situationModule->getKind() == 0) {
        if (ground.isTouch(static_cast<grCollStatus::TouchMask>(8), 0)) {
            Vec2f speed;
            Vec2f::copy(speed, accesser->getKineticModule().getSumSpeed(
                static_cast<soKineticEnergy::AttributeFlag>(1)));
            float squaredLength = speed.lengthSq();
            float length;
            // Keep the ordered comparison: NaN follows the reciprocal-root path.
            if (static_cast<float>(fabs(squaredLength)) <= constants[4]) {
                length = constants[3];
            } else {
                length = squaredLength * rsqrtf(squaredLength);
            }
            if (length > constants[5]) {
                Vec2f normal;
                Vec2f::copy(normal, ground.getTouchNormal(
                    static_cast<grCollStatus::TouchMask>(8), 0));
                fn_8003DBA8(&speed);
                float projection = normal.m_x * speed.m_x + normal.m_y * speed.m_y;
                if (projection > constants[5]) {
                    accesser->getSituationModule().setKind(static_cast<SituationKind>(2), false);
                }
            }
        }
    }
}
