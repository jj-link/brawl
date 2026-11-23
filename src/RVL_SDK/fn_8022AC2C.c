#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern unsigned char lbl_804FB4A0[];
extern void fn_8022DDBC(void);
extern unsigned char *fn_8022C980(unsigned char *);
extern void fn_8023B8DC(unsigned char *, void *);

static inline unsigned char *get_entry(int i)
{
    BOOL state;
    unsigned char *ptr;

    state = OSDisableInterrupts();
    if (i >= 0 && i < 10) {
        ptr = lbl_804FB4A0 + 0xe4 + i * 0x60;
    } else {
        i -= 10;
        ptr = lbl_804FB4A0 + 0x4a4 + i * 0x60;
    }
    OSRestoreInterrupts(state);
    return ptr;
}

static inline void clear_entry(unsigned char *ptr)
{
    unsigned char *p = fn_8022C980(ptr + 0x40);
    BOOL state;
    if (p != 0) {
        state = OSDisableInterrupts();
        memset(p, 0, 0x60);
        OSRestoreInterrupts(state);
    }
}

int fn_8022AC2C(void)
{
    unsigned char *ptr;
    unsigned char *base = lbl_804FB4A0;
    int i;

    if (base[0xe] != 0)
        goto ret2;

    for (i = 0; i < 16; i++) {
        ptr = get_entry(i);
        if (ptr[0x59] != 0) {
            if (ptr[0x5c] == 1) {
                base[0xe] = 3;
                fn_8023B8DC(ptr + 0x40, fn_8022DDBC);
                ptr[0x5c] = 0;
                return 2;
            }
            if (ptr[0x5c] != 3) {
                clear_entry(ptr);
            }
        }
    }
    return 3;

ret2:
    return 2;
}
