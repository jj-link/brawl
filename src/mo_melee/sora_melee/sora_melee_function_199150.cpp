#include <types.h>
#pragma force_active on

struct A {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" s32 fn_27_199150(A* p) {
    return p->c >> 29;
}
