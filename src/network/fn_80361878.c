#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_80362090(void);

int fn_80361878(u8 *arg0, u8 *arg1) {
    int i;

    if (arg0 == 0 || arg1 == 0) {
        return 1;
    }

    if (*(u32 *)(arg0 + 0x64) != 0) {
        return *(u32 *)(arg0 + 0x64);
    }

    if (*(u32 *)(arg0 + 0x60) == 0) {
        fn_80362090();
        for (i = 0; i < 64; i++) {
            arg0[0x1E + i] = 0;
        }
        *(u32 *)(arg0 + 0x14) = 0;
        *(u32 *)(arg0 + 0x18) = 0;
        *(u32 *)(arg0 + 0x60) = 1;
    }

    for (i = 0; i < 20; i++) {
        arg1[i] = (u8)(*(u32 *)(arg0 + (i & 0xFFFFFFFC)) >> ((3 - (i & 3)) * 8));
    }

    return 0;
}
