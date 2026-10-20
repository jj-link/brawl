#include <types.h>
#pragma force_active on

struct FnField8 {
    u32 pad0;
    u32 pad4;
    u32 hi : 10;
    u32 mid : 10;
    u32 lo : 12;
};

extern "C" void fn_27_1A6148(FnField8* p, u32 v) {
    p->mid = v;
}
