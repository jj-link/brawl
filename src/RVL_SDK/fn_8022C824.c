#include <types.h>
#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern char lbl_8047E8D0[];
extern unsigned char lbl_804FB4A0[];
extern void fn_8022E928(const char *, ...);
extern unsigned char *fn_8022C980(int);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_80237540(unsigned char);
extern unsigned char fn_80234EEC(void *);

void fn_8022C824(int arg0)
{
    char *strings = lbl_8047E8D0;
    unsigned char *base = lbl_804FB4A0;
    unsigned char *p;
    int enabled;
    unsigned char type;
    unsigned char value;
    enabled = OSDisableInterrupts();
    fn_8022E928(strings + 0x738);
    p = fn_8022C980(arg0);
    if (p != 0) {
        fn_8022E928(strings + 0x750, p[0x56], p[0x40], p[0x41], p[0x42], p[0x43], p[0x44], p[0x45]);
        fn_8022E928(strings + 0x788);
        if (fn_803F6150(p, strings + 0x224, 0x10) == 0) {
            fn_8022E928(strings + 0x7ac);
            fn_8022E928(strings + 0x7c0, p[0x56]);
            fn_80237540(p[0x56]);
        }
        value = fn_80234EEC(p + 0x40);
        fn_8022E928(strings + 0x7d0, value);
        type = p[0x5b];
        if (type == 0 || type == 2 || (unsigned char)(type + 0xfc) <= 1U) {
            base[0x12]--;
        } else {
            base[0x13]--;
        }
        memset(p, 0, 0x60);
    }
    OSRestoreInterrupts(enabled);
}