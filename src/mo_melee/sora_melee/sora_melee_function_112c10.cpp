#include <types.h>
#pragma force_active on

struct fn27Inner {
    char pad[0x5c];
    s32 val;
};

struct fn27Outer {
    fn27Inner* inner;
    u8 pad[6];
    u8 state;
};

extern "C" void fn_27_112C10(fn27Outer* p, s32 amount) {
    if (p->state != 1) {
        return;
    }
    fn27Inner* in = p->inner;
    s32 max = 0x7FFFFFFF - in->val;
    if (max < amount) {
        amount = max;
    }
    in->val += amount;
}
