#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_11E34(void* self, u8 val) {
    u8* a = *(u8**)((u8*)self + 0x28);
    if (a) {
        a[0x42] = val;
        a[0x43] = val;
        return;
    }
    u8* b = *(u8**)((u8*)self + 0x2c);
    if (b) {
        u8* c = *(u8**)b;
        c[0x42] = val;
        c[0x43] = val;
    }
}
}
