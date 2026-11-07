#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_27_32E194(void*, soModuleAccesser* accesser) {
    soCollisionAttackModule* attack = accesser->m_enumerationStart->m_collisionAttackModule;
    if (attack->isAttack(0, false)) {
        attack->setPower(0, accesser->m_enumerationStart->m_workManageModule->getInt(0x20000001), false);
    }
}
