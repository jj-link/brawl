#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" const float lbl_114_rodata_B0[4];
extern "C" Vec3f* fn_114_12B94(Vec3f*, float, float, float);

extern "C" void fn_114_12A0C(void*, soModuleAccesser* accesser) {
    const float* data = lbl_114_rodata_B0;
    accesser->m_enumerationStart->m_collisionAbsorberModule->setStatus(0, 1, 0);

    if (accesser->m_enumerationStart->m_workManageModule->getInt(0x20000003) < 0) {
        soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
        Vec3f pos;
        Vec3f rot;
        u32 handle = effect->reqFollow(
            (EfID)0x1B000F, 2,
            fn_114_12B94(&pos, data[0], data[1], data[2]),
            fn_114_12B94(&rot, data[0], data[0], data[0]),
            data[3], false, 0, 0, -1);
        accesser->m_enumerationStart->m_workManageModule->setInt(handle, 0x20000003);
    }

    if (accesser->m_enumerationStart->m_workManageModule->getInt(0x20000002) < 0) {
        int handle = accesser->m_enumerationStart->m_soundModule->playSE(
            (SndID)0x1450, true, 0, 0);
        accesser->m_enumerationStart->m_workManageModule->setInt(handle, 0x20000002);
    }
}
