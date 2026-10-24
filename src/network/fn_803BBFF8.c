#include <types.h>
#pragma force_active on

s32 fn_803BBFF8(void *arg0, void **arg1) {
    int i;

    if (arg0 == NULL || arg1 == NULL || *(s32 *)((char *)arg0 + 0x22C) == 0) {
        return 0xA;
    }
    *(u32 **)arg1 = NULL;
    for (i = 0; i < 5; i++) {
        if ((*(u32 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x40) & 1) &&
            (*(u32 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x40) & 2) &&
            *(u32 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x2A8) ==
                *(u32 *)((char *)arg0 + 0x22C) &&
            *(u32 *)((char *)arg0 + 0x238) ==
                *(u32 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x2B4) &&
            *(u16 *)((char *)arg0 + 0x23C) ==
                *(u16 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x2B8)) {
            *(u32 **)arg1 = (u32 *)(*(u32 *)((char *)arg0 + 0x22C) + i * 0x290 + 0x7C);
        }
    }
    return 0;
}
