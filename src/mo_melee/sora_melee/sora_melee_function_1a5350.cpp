#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    u32 c : 18;
    u32 y : 1;
    u32 e : 13;
};

extern "C" u32 fn_27_1A5350(S *p) {
    return p->y;
}
