#include <types.h>
#pragma force_active on

extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern u8 lbl_80406938[];

extern "C" {
void fn_8004DA50(void* dst) {
    memcpy(dst, lbl_80406938, 0x2D);
}
}
