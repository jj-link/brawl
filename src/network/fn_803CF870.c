#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state;
    int unused;
    int error;
} State;

typedef struct {
    int a, b, c, d;
    char pad[0x18c - 16];
    int kind;
    int index;
} Entry;

extern int fn_803CD270(void);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern int fn_803CD32C(void);
extern void fn_8020B898(void *, void *);
extern int fn_8020ACD8(void *, int, int, void (*)(void), void *);
extern void fn_803CF560(void);

void fn_803CF870(int a, int b, int c, int d, int e)
{
    int result;
    BOOL enabled;
    int *info;
    void *buf;
    char *ptr;
    Entry *entry;

    if (fn_803CD270())
        ptr = (char *)fn_803CD3B4(a) + 0x48;
    else
        ptr = 0;

    entry = fn_803CD3B4(a);
    enabled = OSDisableInterrupts();
    fn_803CD318(1);
    fn_803CD324()->state = 6;
    OSRestoreInterrupts(enabled);

    entry->a = d;
    entry->b = b;
    entry->c = c;
    entry->d = e;

    buf = (char *)fn_803CD3B4(a) + 0xd4;
    entry = fn_803CD3B4(a);
    info = &entry->kind;
    info[0] = 12;
    info[1] = a;
    fn_8020B898(buf, info);

    result = fn_8020ACD8(ptr, e, 0, fn_803CF560, buf);
    switch (result) {
    case 0:
        break;

    case -1:
    case -3:
        switch (fn_803CD324()->state) {
        case 0:
        case 6: {
            BOOL enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 2;
            fn_803CD324()->error = result;
            OSRestoreInterrupts(enabled);
            break;
        }
        }
        break;

    case -8:
    case -64:
    case -128:
    default:
        switch (fn_803CD324()->state) {
        case 0:
        case 6: {
            BOOL enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 5;
            fn_803CD324()->error = result;
            OSRestoreInterrupts(enabled);
            break;
        }
        }
        break;
    }

    fn_803CD32C();
}
