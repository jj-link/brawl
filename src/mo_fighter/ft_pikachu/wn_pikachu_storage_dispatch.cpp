#include <wn/weapon.h>

extern "C" {
void* fn_98_17D34(void* owner);
void* fn_98_17CEC(void* owner);
void fn_98_140E4(void* storage, bool enabled);
void fn_98_98B0(void* storage);
void fn_98_1829C(void* owner);
void fn_98_181C0(void* owner);
void fn_98_141E8(void* storage, int valueC, int valueD);
void fn_98_14074(void* storage, bool enabled);

void fn_98_180A4(Weapon* owner) {
    soWorkManageModule* work = &owner->m_moduleAccesser->getWorkManageModule();
    void* primary;
    if (work->isFlag(0x12000006)) {
        const int valueC = work->getInt(0x1000000c);
        const int valueD = work->getInt(0x1000000d);
        primary = fn_98_17D34(owner);
        if (primary) {
            fn_98_140E4(primary, true);
        }
        void* secondary = fn_98_17CEC(owner);
        if (secondary) {
            fn_98_98B0(secondary);
        }
        fn_98_1829C(owner);
        fn_98_181C0(owner);
        if (primary) {
            fn_98_141E8(primary, valueC, valueD);
            fn_98_14074(primary, true);
        }
        work->offFlag(0x12000006);
    }
}
}
