#include <types.h>
#pragma force_active on

struct S {
    u32 a;
    u32 b;
    signed int field : 2;
};

extern "C" int fn_27_19C27C(S* p) {
    return p->field;
}
