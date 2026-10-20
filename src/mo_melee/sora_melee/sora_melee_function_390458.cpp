#include <types.h>
#pragma force_active on

struct Reg {
    u32 f : 6;
    u32 pad : 26;
};

extern "C" void fn_27_390458(void* base, u32 val) {
    Reg* r = (Reg*)((char*)base + 8);
    r->f = val;
}
