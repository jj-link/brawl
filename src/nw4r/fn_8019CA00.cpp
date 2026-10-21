#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x3e];
    u16 value;
};

struct Outer {
    u8 pad[0x20];
    Inner* inner;
};

extern "C" u16 fn_8019CA00(Outer* arg0) {
    return arg0->inner->value;
}
