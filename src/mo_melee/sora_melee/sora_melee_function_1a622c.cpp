#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 field : 10;
};

extern "C" void fn_27_1A622C(struct X* p, u32 val) {
    p->field = val;
}
