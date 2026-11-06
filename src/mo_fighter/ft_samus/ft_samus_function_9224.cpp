#include <so/so_module_accesser.h>
#include <so/stageobject.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_12DCA8(void*);
Vec3f* fn_94_94E0(Vec3f*, float, float, float);
extern const float lbl_94_rodata_0[];
}

extern "C" void fn_94_9224(StageObject* self) {
    const float* constants = lbl_94_rodata_0;
    fn_27_12DCA8(self);
    soModuleAccesser* accesser = self->m_moduleAccesser;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
    int* params = *reinterpret_cast<int**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3)) + 0x7c);
    if (accesser->m_enumerationStart->m_workManageModule->getInt(0x10000041) >= *params) {
        if (work->getInt(0x10000040) == 0) {
            Vec3f unused;
            fn_94_94E0(&unused, constants[4], constants[3], constants[3]);
            Vec3f pos, rot;
            int handle = effect->reqFollow((EfID)0x40006, 0x2b,
                fn_94_94E0(&pos, constants[4], constants[3], constants[3]),
                fn_94_94E0(&rot, constants[3], constants[3], constants[3]),
                constants[1], true, 0, 0, -1);
            work->setInt(handle, 0x10000040);
        }
        int handle = accesser->m_enumerationStart->m_workManageModule->getInt(0x10000040);
        float scale = accesser->m_enumerationStart->m_postureModule->getScale();
        effect = self->m_moduleAccesser->m_enumerationStart->m_effectModule;
        Vec3f size(scale, scale, scale);
        effect->setScale(handle, &size);
        if (accesser->m_enumerationStart->m_visibilityModule->get(1) != 1) {
            Vec3f pos;
            effect->setPos(handle, fn_94_94E0(&pos, constants[4], constants[3], constants[3]));
        } else {
            Vec3f pos;
            effect->setPos(handle, fn_94_94E0(&pos, constants[3], constants[3], constants[3]));
        }
    } else if (work->getInt(0x10000040) != 0) {
        effect->kill(accesser->m_enumerationStart->m_workManageModule->getInt(0x10000040), true, true);
        work->setInt(0, 0x10000040);
    }
}
