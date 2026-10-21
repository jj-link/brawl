#include <types.h>
#pragma force_active on

extern u8 lbl_80529CF8[];
void* memset(void* dst, int c, unsigned long n);

void fn_80240618(u8 val) {
    lbl_80529CF8[0x1978] = val;
    memset(lbl_80529CF8 + 0x1954, 0xff, 6);
}
