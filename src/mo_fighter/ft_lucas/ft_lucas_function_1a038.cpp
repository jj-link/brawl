#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern const float lbl_114_rodata_110;
extern const float lbl_114_rodata_114;
Vec3f* fn_114_12B94(Vec3f*, float, float, float);
}
extern "C" void fn_114_1A038(void* self, soModuleAccesser* accesser) {
    soPostureModule* posture = accesser->m_enumerationStart->m_postureModule;
    soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
    Vec3f pos;
    posture->setRot(fn_114_12B94(&pos, lbl_114_rodata_110, lbl_114_rodata_110, lbl_114_rodata_110), 0);
    effect->req((EfID)0x22, &posture->getPos(), fn_114_12B94(&Vec3f(), lbl_114_rodata_110, lbl_114_rodata_110, lbl_114_rodata_110), lbl_114_rodata_114, 0, -1);
}