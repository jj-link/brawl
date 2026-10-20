#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[0x1f];
    u8 a : 6;
    u8 flag : 1;
    u8 b : 1;
};

struct Outer {
    Inner* inner;
};

extern "C" {
bool fn_27_112D44(Outer* p) {
    return p->inner->flag;
}
}
