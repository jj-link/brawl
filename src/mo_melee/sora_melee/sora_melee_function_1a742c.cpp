#include <types.h>
#pragma force_active on

struct Foo {
    s32 a;
    s32 b;
    unsigned int lo : 8;
    signed int val : 4;
    unsigned int hi : 20;
};

extern "C" s32 fn_27_1A742C(Foo* p) {
    return p->val;
}
