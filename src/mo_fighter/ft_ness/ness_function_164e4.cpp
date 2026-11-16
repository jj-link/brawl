#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern const float lbl_101_rodata_B8;
extern const float lbl_101_rodata_BC;
Vec3f* fn_101_1303C(Vec3f*, float, float, float);
}
extern "C" void fn_101_164E4(void* self, soModuleAccesser* accesser, int arg) {
    soPostureModule* posture = accesser->m_enumerationStart->m_postureModule;
    soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
    Vec3f pos;
    posture->setRot(fn_101_1303C(&pos, lbl_101_rodata_B8, lbl_101_rodata_B8, lbl_101_rodata_B8), 0);
    if (arg != 1) {
        effect->req((EfID)0x22, &posture->getPos(), fn_101_1303C(&Vec3f(), lbl_101_rodata_B8, lbl_101_rodata_B8, lbl_101_rodata_B8), lbl_101_rodata_BC, 0, -1);
    }
}