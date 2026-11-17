#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int fn_803F6150(const void *, const void *, unsigned long);
extern char lbl_804FB4A0[];

typedef struct { char data[0x60]; } Entry;
typedef struct {
    char pad[0xE4];
    Entry first[10];
    Entry second[6];
} State;

void *fn_8022C980(void *arg0)
{
    char *base;
    void *ret;
    s32 irq;
    s32 i;
    s32 off;
    char *p;

    base = lbl_804FB4A0;
    ret = 0;
    irq = OSDisableInterrupts();
    p = base + 0x124;
    for (i = 0; i < 10; i++) {
        if (fn_803F6150(p, arg0, 6) == 0) {
            off = i * 0x60;
            ret = &((State *)base)->first[i];
            break;
        }
        p += 0x60;
    }
    if (ret == 0) {
        p = base + 0x4E4;
        for (i = 0; i < 6; i++) {
            if (fn_803F6150(p, arg0, 6) == 0) {
                off = i * 0x60;
                ret = &((State *)base)->second[i];
                break;
            }
            p += 0x60;
        }
    }
    OSRestoreInterrupts(irq);
    return ret;
}
