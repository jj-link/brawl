#include <types.h>
#pragma force_active on

struct Obj {
    char pad[8];
    s32 f;
};

extern "C" {
s32 fn_27_CD05C(Obj* p) {
    s32 t = p->f;
    t = (t << 6) & 0xF0000000;
    return t >> 29;
}
}
