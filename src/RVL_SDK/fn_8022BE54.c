#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern u8 lbl_8047EDD0[];
extern u8 lbl_804FB4A0[];

void fn_8022E928(const char* fmt, ...);
s32 OSDisableInterrupts(void);
void OSRestoreInterrupts(s32 level);
void fn_80234D38(void);

s32 fn_8022BE54(void) {
    s32 irq;
    s32 ret;
    u8* base;

    fn_8022E928((const char*)lbl_8047EDD0);
    base = lbl_804FB4A0;
    ret = 0;
    irq = OSDisableInterrupts();
    if ((s32)base[0x708] == 3) {
        if ((s8)base[0x6E8] != 0) {
            if (base[0xC] == 3) {
                fn_80234D38();
            }
            base[0x6E8] = 0;
        }
        ret = 1;
    }
    OSRestoreInterrupts(irq);
    return ret;
}
