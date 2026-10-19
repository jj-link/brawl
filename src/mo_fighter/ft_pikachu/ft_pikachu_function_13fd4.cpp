#include <wn/weapon.h>
#pragma force_active on

extern "C" {
void fn_98_140E4(void*, bool);
void fn_98_14298(void*, int);
void* fn_98_14750(void*);
void* fn_98_14878(void*);
void fn_98_17F20(void*, void*);
void fn_98_17F24(void*, void*);

void fn_98_13FD4(Weapon* storage) {
    void* accesser = storage->m_moduleAccesser;
    fn_98_140E4(storage, false);
    fn_98_14298(accesser, 0x1000000A);
    fn_98_14298(accesser, 0x1000000B);

    void* owner = fn_98_14750(storage);
    if (owner != 0) {
        fn_98_17F20(owner, fn_98_14878(storage));
        fn_98_17F24(owner, storage);
    }

    storage->remove();
}
}
