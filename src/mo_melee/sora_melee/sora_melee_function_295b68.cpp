#include <types.h>
#pragma force_active on

struct fn_27_295B68_obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 3;
    u32 rest : 29;
};

extern "C" void fn_27_295B68(fn_27_295B68_obj* p, u32 v) {
    p->hi = v;
}
