#include <wn/weapon.h>

extern "C" void fn_98_17FF4(Weapon* owner, int valueC, int valueD) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    work->onFlag(0x12000005);
    work->setInt(valueC, 0x1000000c);
    work->setInt(valueD, 0x1000000d);
    work->onFlag(0x12000006);
}
