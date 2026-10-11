#include <wn/weapon.h>

extern "C" {
void* fn_98_18248();
int fn_27_5013C(void* manager);

void fn_98_181C0(Weapon* owner) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    const int selection = fn_27_5013C(fn_98_18248());
    work->setInt(selection, 0x1000000a);
    if (selection != -1) {
        work->onFlag(0x12000003);
    }
}
}
