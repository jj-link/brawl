#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_107_127B4(int a, soModuleAccesser* accesser) {
    soCollisionAttackModule* attack = &accesser->getCollisionAttackModule();
    float power = accesser->getWorkManageModule().getFloat(0x21000006);
    for (int i = 0; i < 4; i++) {
        if (attack->isAttack(i, false)) {
            attack->setPower(i, static_cast<int>(power), false);
        }
    }
}
