#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
int fn_27_1922CC(void*, unsigned long);
}

extern "C" void fn_27_3A2038(void* unused, soModuleAccesser* arg) {
    s32 i;
    soWorkManageModule* wm = arg->m_enumerationStart->m_workManageModule;
    s32 power = fn_27_1922CC(arg, 0x5dc1) + (wm->getInt(0x20000000) / 30) * fn_27_1922CC(arg, 0x5dc2);
    for (i = 0; i < (s32)arg->m_enumerationStart->m_collisionAttackModule->getPartSize(); i++) {
        if (arg->m_enumerationStart->m_collisionAttackModule->isAttack(i, false)) {
            arg->m_enumerationStart->m_collisionAttackModule->setPower(i, power, false);
        }
    }
}
