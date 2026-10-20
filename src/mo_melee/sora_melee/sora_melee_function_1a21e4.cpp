#include <types.h>
#pragma force_active on

struct Fld {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

extern "C" void fn_27_1A21E4(void *self, u32 val) {
    Fld *p = (Fld *)((u8 *)self + 8);
    p->f = val;
}
