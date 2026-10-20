#include <types.h>
#pragma force_active on

struct Fn1A7564Arg {
    u8 pad[8];
    u32 flags;
};

extern "C" {
s32 fn_27_1A7564(Fn1A7564Arg *p) {
    return (s32)(((p->flags >> 22) & 0xF) << 28) >> 29;
}
}
