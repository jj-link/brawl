#include <types.h>
#pragma force_active on

extern void fn_803D4E0C(void);
extern void *memset(void *s, int c, unsigned long n);

void fn_803D5014(void *unused, u8 *arg1) {
    fn_803D4E0C();
    memset(arg1 + 0x2E, 0, 0x14);
    *(u16 *)(arg1 + 0x42) = 0;
    *(u16 *)(arg1 + 0x44) = *(u16 *)(arg1 + 0x44) & 0xFFFF803F;
}
