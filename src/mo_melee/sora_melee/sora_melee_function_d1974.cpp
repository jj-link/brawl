#include <types.h>
#pragma force_active on

struct FieldWord {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

extern "C" void fn_27_D1974(void* p, u32 v) {
    FieldWord* w = (FieldWord*)((u32*)p + 2);
    w->b = v;
}
