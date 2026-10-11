#include <wn/weapon.h>

extern "C" {
void fn_98_1834C(Weapon* owner, soCollisionAttackModule* attack) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    if (work->isFlag(0x12000003)) {
        const int group = work->getInt(0x1000000a);
        attack->refLogGroup(0, group);
    }
}

void fn_98_183E4(void*, soCollisionAttackModule* attack) {
    attack->unRefLogGroup(0);
}
}
