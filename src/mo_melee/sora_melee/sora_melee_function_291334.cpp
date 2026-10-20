#include <types.h>
#pragma force_active on

struct S {
    s32 a;
    s32 b;
    unsigned : 5;
    signed c : 5;
};

extern "C" s32 fn_27_291334(const S* p) {
    return p->c;
}
