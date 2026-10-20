#include <types.h>
#pragma force_active on

extern "C" void fn_27_12928(u8* self, u8 val) {
    u8* p = *(u8**)(self + 0x28);
    if (p != 0) {
        p[0xe8] = val;
        return;
    }
    p = *(u8**)(self + 0x2c);
    if (p == 0) {
        return;
    }
    p = *(u8**)p;
    p[0xe8] = val;
}
