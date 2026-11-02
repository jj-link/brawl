#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_8022E928(const char *fmt, ...);
extern char lbl_8047F0BC[];
extern unsigned char lbl_804FB4A0[];

void *fn_8022CA58(void) {
    unsigned char *base = lbl_804FB4A0;
    void *result = NULL;
    BOOL enabled;
    s32 i;
    unsigned char *p;
    s32 addr;

    enabled = OSDisableInterrupts();
    if (base[0x6E9] == 0) {
        p = base;
        for (i = 0; i < 10; i++) {
            if (p[0x13D] == 0) {
                fn_8022E928(lbl_8047F0BC, i);
                addr = (s32)base + i * 0x60;
                result = (void *)(addr + 0xE4);
                break;
            }
            p += 0x60;
        }
    } else {
        result = *(void **)(*(char **)(base + 0x18));
    }
    OSRestoreInterrupts(enabled);
    return result;
}
