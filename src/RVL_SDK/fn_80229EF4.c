#pragma force_active on
#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSAlarm.h>

extern u8 lbl_804FB4A0[];
extern char lbl_8047EAE4[];
extern void fn_8022E928(const char *, ...);
extern void fn_80234C5C(int, int);
extern void fn_8023D97C(u8, void *, void *);

typedef struct { u8 b[0x60]; } Entry;
typedef struct { u8 pad[0xE4]; Entry a[10]; Entry b[6]; } Mgr;

static inline u8 *getEntry(int i) {
    u8 *p;
    int level = OSDisableInterrupts();
    Mgr *m = (Mgr *)lbl_804FB4A0;
    if (i >= 0 && i < 10)
        p = m->a[i].b;
    else
        p = m->b[i - 10].b;
    OSRestoreInterrupts(level);
    return p;
}

s32 fn_80229EF4(void) {
    u8 *ptr;
    u8 *base;
    int i;
    void (*fp)(int, int);
    struct {
        s16 a;
        s16 b;
        s16 c;
        s16 d;
        s8 e;
    } info;

    base = lbl_804FB4A0;
    if (base[0x6E7] != 0) {
        for (i = 0; i < 16; i++) {
            ptr = getEntry(i);
            if (ptr[0x59] == 8) {
                info.e = 2;
                info.a = 8;
                info.b = 8;
                info.c = 1;
                info.d = 0;
                fn_8023D97C(lbl_804FB4A0[0x70A], ptr + 0x40, &info);
                return 0xE;
            }
        }
    }

    OSCancelAlarm((OSAlarm *)(base + 0x710));
    {
        int level = OSDisableInterrupts();
        lbl_804FB4A0[0x6EB] = 0;
        lbl_804FB4A0[0x6EA] = 1;
        OSRestoreInterrupts(level);
    }
    fn_80234C5C(0, 1);

    if (base[0x6E9] == 0) {
        fp = *(void (**)(int, int))base;
    } else {
        fp = *(void (**)(int, int))(base + 4);
    }
    if (fp != 0) {
        fp(1, base[0x6E6]);
    }

    fn_8022E928(lbl_8047EAE4);
    return 0;
}