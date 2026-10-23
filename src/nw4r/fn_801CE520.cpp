#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" {
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void fn_801CCB80(s32, s32);
void fn_801D0DA4(s32);
}

extern "C" void fn_801CE520(u8* self) {
    const s32& irq = OSDisableInterrupts();
    u8* p = self;
    s32 i = 0;

    while (i < *(s32*)(self + 0x7C4)) {
        s32 value = *(s32*)(p + 0x7CC);
        if (value != 0) {
            fn_801CCB80(*(s32*)(self + 0x7B8), value);
            *(s32*)(p + 0x7CC) = 0;
            *(s32*)(p + 0x7D0) = 0;
        }
        p += 0x38;
        i++;
    }

    *(s32*)(self + 0x7C4) = 0;
    if (*(s32*)(self + 0x7C0) != 0) {
        fn_801D0DA4(*(s32*)(self + 0x7C0));
        *(s32*)(self + 0x7C0) = 0;
    }

    OSRestoreInterrupts(irq);
}
