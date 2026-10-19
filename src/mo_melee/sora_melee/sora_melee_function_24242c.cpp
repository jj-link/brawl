#include <types.h>
#pragma force_active on

struct SoraMeleeGimmick {
    u8 _pad0[0x40];
    u8 byte40;
    u8 _pad41[0x1D];
    u8 byte5E;
};

extern "C" void fn_27_24242C(SoraMeleeGimmick* obj) {
    if (obj->byte40 != 0)
        return;
    obj->byte40 = 1;
    obj->byte5E = 0;
}
