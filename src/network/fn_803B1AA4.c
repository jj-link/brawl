#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_803B84E8(void *p);

void fn_803B1AA4(char *arg0) {
    u32 i;
    u32 zero;
    char *temp;

    zero = 0;
    i = 0;
    do {
        temp = arg0 + (u16)i * 0x280;
        *(u32 *)(temp + 0xE00) = zero;
        fn_803B84E8(temp + 0xE08);
        i++;
    } while (i < 3);

    *(u32 *)(arg0 + 0x1580) &= ~1;
    *(u32 *)(arg0 + 0x15A0) &= ~1;
    *(u32 *)(arg0 + 0x15C0) &= ~1;
    *(u32 *)(arg0 + 0x15E4) = 0;
}
