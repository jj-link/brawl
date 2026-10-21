#include <types.h>
#pragma force_active on

extern void fn_80230064(void* t);

struct Obj {
    char pad[0xc];
    u32 field0C;
    u8 field10;
};

void fn_802325A0(struct Obj* a, u32 b, u8 c) {
    fn_80230064(a);
    a->field0C = b;
    a->field10 = c;
}
