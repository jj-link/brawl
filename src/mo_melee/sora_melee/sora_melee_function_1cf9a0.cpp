#include <types.h>
#pragma force_active on

struct S {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" s32 fn_27_1CF9A0(S* s) {
    return s->c >> 26;
}
