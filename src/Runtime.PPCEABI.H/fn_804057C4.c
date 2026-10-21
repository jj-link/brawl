#pragma force_active on
typedef unsigned long u32;

extern u32 fn_80403770(void *);
extern unsigned char gTRKState[];
extern u32 lbl_8059BEC8;

u32 TRKInitializeTarget(void) {
    *(u32 *)(gTRKState + 0x98) = 1;
    *(u32 *)(gTRKState + 0x8C) = fn_80403770(gTRKState);
    lbl_8059BEC8 = 0xE0000000;
    return 0;
}
