#include <wn/weapon.h>
#pragma force_active on

extern "C" {
void* fn_98_9890(Weapon* owner);
void fn_98_1834C(void* owner, soCollisionAttackModule* attack);

void fn_98_11100(void*, Weapon* owner) {
    soWorkManageModule* work = (soWorkManageModule*)*(void**)((char*)*(void**)((char*)owner + 0xd8) + 0x64);
    work->setInt(-1, 0x20000002);
    void* result = fn_98_9890(owner);
    if (result != 0) {
        fn_98_1834C(result, *(soCollisionAttackModule**)((char*)*(void**)((char*)owner + 0xd8) + 0x1c));
        work->onFlag(0x22000012);
    }
}
}
