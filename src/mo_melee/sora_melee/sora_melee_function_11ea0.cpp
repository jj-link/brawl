#include <types.h>
#pragma force_active on

extern "C" void fn_27_11EA0(u8* self, int flag) {
    u8* b = *(u8**)(self + 0x2c);
    if (b == 0) {
        return;
    }
    u8* c = *(u8**)b;
    if (c != 0) {
        if (c[0x20] == 0 && flag != 0) {
            c[0xe] = 1;
        }
        c[0x20] = flag;
    }
    u8* d = *(u8**)(b + 4);
    if (d == 0) {
        return;
    }
    d[0x20] = flag;
}
