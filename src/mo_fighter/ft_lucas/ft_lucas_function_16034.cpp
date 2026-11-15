#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern const float lbl_114_rodata_D8;
extern const float lbl_114_rodata_DC;
Vec3f* fn_114_12B94(Vec3f*, float, float, float);
}
extern "C" void fn_114_16034(void* self, soModuleAccesser* accesser, int arg) {
    soPostureModule* posture = accesser->m_enumerationStart->m_postureModule;
    soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
    Vec3f pos;
    posture->setRot(fn_114_12B94(&pos, lbl_114_rodata_D8, lbl_114_rodata_D8, lbl_114_rodata_D8), 0);
    if (arg != 1) {
        effect->req((EfID)0x22, &posture->getPos(), fn_114_12B94(&Vec3f(), lbl_114_rodata_D8, lbl_114_rodata_D8, lbl_114_rodata_D8), lbl_114_rodata_DC, 0, -1);
    }
}
