#include <types.h>
#pragma force_active on

extern "C" void fn_8011031C(void* arg0) {
    if (arg0 == 0) return;

    u8* p = (u8*)arg0;
    if (p[1] != 0) {
        p[0x18] = 0x78;
        *(u16*)(p + 0xC) = 0;
        return;
    }

    unsigned val = p[0x1C];
    if ((val >> 5) & 1) return;

    u16 hw = *(u16*)(p + 0xC);
    if (hw == 0) return;

    p[0x1C] = (u8)(val | 0x20);
}
