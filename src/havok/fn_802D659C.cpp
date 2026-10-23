#include <types.h>
#pragma force_active on

extern u8 lbl_80487828[0x40];

struct Obj {
    void* vt;
    u16 _4;
    s16 flag;
    u8 pad[0x36];
} __attribute__((aligned(16)));

extern "C" void* fn_802D659C() {
    Obj obj;
    if (&obj != 0) {
        obj.flag = 1;
        obj.vt = lbl_80487828;
    }
    return obj.vt;
}
