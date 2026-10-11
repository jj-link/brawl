#include <wn/weapon.h>

extern "C" {
void* fn_98_18248();
void fn_27_50330(void* manager, int selection);
void fn_27_50190(void* manager, int selection);

void fn_98_1829C(Weapon* owner) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    if (work->isFlag(0x12000003)) {
        const int selection = work->getInt(0x1000000a);
        fn_27_50330(fn_98_18248(), selection);
        fn_27_50190(fn_98_18248(), selection);
    }
    work->offFlag(0x12000003);
}
}
