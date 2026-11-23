#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state;
    int unused;
    int error;
} State;

typedef struct {
    void (*fn)(void);
    char pad[0x45 - 4];
    unsigned char value;
    char pad2[0x18c - 0x46];
    int kind;
    int index;
    char pad3[0x1d4 - 0x194];
    void *buffer;
} Entry;

extern int fn_8020B8A0(int);
extern Entry *fn_803CD3B4(int);
extern int fn_803CD270(void);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern void fn_8020B898(void *, void *);
extern int fn_8020BD30(void *, void *, int, void *, int, void (*)(void), void *);
extern void fn_803CE640(void);
extern void *memset(void *, int, unsigned long);

void fn_803CE924(int arg0, int arg1)
{
    int index, result;
    Entry *entry;
    int *info;
    void *buf;
    char *ptr;
    BOOL enabled;
    int call = 1;

    index = *(int *)((char *)fn_8020B8A0(arg1) + 4);
    entry = fn_803CD3B4(index);

    switch (arg0) {
    case 0:
    case -6:
        buf = (char *)fn_803CD3B4(index) + 0xd4;
        info = &fn_803CD3B4(index)->kind;
        info[0] = 11;
        info[1] = index;
        fn_8020B898(buf, info);
        memset(entry->buffer, 0, 0x2000);

        if (fn_803CD270())
            ptr = (char *)fn_803CD3B4(index) + 0x48;
        else
            ptr = 0;

        result = fn_8020BD30((char *)entry + 4, ptr, entry->value,
                             entry->buffer, 0x2000, fn_803CE640, buf);

        switch (result) {
        case 0:
            call = 0;
            break;
        case -1:
        case -3:
        case -10:
        case -12:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                index = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 2;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(index);
                break;
            }
            break;
        case -2:
        case -9:
        case -4:
        case -5:
        case -6:
        case -7:
        case -11:
        case -64:
        case -128:
        default:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 5;
                fn_803CD324()->error = arg0;
                OSRestoreInterrupts(enabled);
                break;
            }
            break;
        }
        break;
    case -1:
    case -3:
    case -4:
    case -11:
        switch (fn_803CD324()->state) {
        case 0:
        case 6:
            enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 2;
            fn_803CD324()->error = arg0;
            OSRestoreInterrupts(enabled);
            break;
        }
        break;
    case -9:
    case -10:
    case -2:
    case -5:
    case -7:
    case -64:
    case -128:
    default:
        switch (fn_803CD324()->state) {
        case 0:
        case 6:
            enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 5;
            fn_803CD324()->error = arg0;
            OSRestoreInterrupts(enabled);
            break;
        }
        break;
    }

    if (call != 0 && entry->fn != 0)
        entry->fn();
}
