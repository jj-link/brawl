#include <wn/weapon.h>

extern "C" void fn_98_17F24(Weapon* owner) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    work->incInt(0x10000009);
    const int active = work->getInt(0x10000007);
    const int threshold = work->getInt(0x10000008);
    const int elapsed = work->getInt(0x10000009);
    if (active <= 0 && elapsed >= threshold) {
        owner->deactivate(false);
    }
}
