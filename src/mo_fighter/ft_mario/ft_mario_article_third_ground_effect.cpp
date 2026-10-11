#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_91_rodata_98;
extern const float lbl_91_rodata_9C;
Vec3f* fn_91_169EC(Vec3f*, const Vec3f&);
bool fn_27_31174(soModuleAccesser*, Vec3f*, Vec3f*, int*, Vec3f*, Vec3f*, bool);
void fn_91_19184(void*, soModuleAccesser* accesser, unsigned int node, const Vec3f* target, Vec3f* origin) {
    Vec3f direction;
    Vec3f hitPosition;
    Vec3f hitNormal;
    Vec3f rotation;
    int line = 0xffff;
    Vec3f nodePosition = accesser->getModelModule().getNodeGlobalPosition(node, false);
    fn_91_169EC(origin, nodePosition);
    origin->m_z = lbl_91_rodata_98;
    Vec3f difference;
    Vec3fSub(&difference, target, origin);
    fn_91_169EC(&direction, difference);
    if (fn_27_31174(accesser, origin, &direction, &line, &hitPosition, &hitNormal, true) == true) {
        rotation.m_z = lbl_91_rodata_98;
        rotation.m_x = lbl_91_rodata_98;
        rotation.m_y = accesser->getPostureModule().getRotYLr();
        Vec3f rotationRange;
        rotationRange.m_x = lbl_91_rodata_98;
        rotationRange.m_y = lbl_91_rodata_98;
        rotationRange.m_z = lbl_91_rodata_98;
        int effectLine = line;
        accesser->getEffectModule().reqAttachGround(ef_ptc_fin_mario_fire_remain, &effectLine, &hitPosition,
                                                   &rotation, lbl_91_rodata_9C, &rotationRange, 0);
    }
}
}
