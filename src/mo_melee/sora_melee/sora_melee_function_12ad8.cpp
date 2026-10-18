#include <types.h>
#pragma force_active on

struct Fn27Inner {
    u8 pad[0xe];
    u8 flag;
};

struct Fn27Outer {
    u8 pad[0x28];
    Fn27Inner* inner;
};

extern "C" void fn_27_12AD8(Fn27Outer* p) {
    Fn27Inner* inner = p->inner;
    if (inner == 0) {
        return;
    }
    inner->flag = 1;
}
