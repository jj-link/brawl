#include <types.h>
#pragma force_active on

struct Flags {
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" void fn_27_19AA4C(void* r3, u32 r4) {
    Flags* p = (Flags*)((char*)r3 + 8);
    p->f = r4;
}
