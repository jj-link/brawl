#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state, unused, error;
} State;

typedef struct {
    void (*callback)(void);
    int data, size, expected;
    char pad[0x18c - 16];
    int kind, index;
} Entry;

extern int fn_803CD270(void);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern void fn_8020B898(void *, void *);
extern int *fn_8020B8A0(int);
extern int fn_8020AAE0(void *, int, int, void (*)(int, int), void *);
extern void fn_803CF2E8(int, int);

void fn_803CF560(int result, int arg)
{
    Entry *entry;
    int *info;
    char *ptr;
    int call;

    arg = fn_8020B8A0(arg)[1];
    entry = fn_803CD3B4(arg);
    call = 1;

    if (result == entry->expected) {
        result = (int)((char *)fn_803CD3B4(arg) + 0xd4);
        info = &fn_803CD3B4(arg)->kind;
        info[0] = 13;
        info[1] = arg;
        fn_8020B898((void *)result, info);

        if (fn_803CD270())
            ptr = (char *)fn_803CD3B4(arg) + 0x48;
        else
            ptr = 0;

        result = fn_8020AAE0(ptr, entry->data, (entry->size + 31) & ~31,
                             fn_803CF2E8, (void *)result);
        switch (result) {
        case 0:
            call = 0;
            break;

        case -1:
        case -3:
        case -4:
        case -5:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                arg = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 2;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(arg);
                break;
            }
            break;

        case -2:
        case -8:
        case -64:
        case -128:
        default:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                arg = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 5;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(arg);
                break;
            }
            break;
        }
    } else if (result >= 0) {
        switch (fn_803CD324()->state) {
        case 0:
        case 6:
            result = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 3;
            fn_803CD324()->error = 0;
            OSRestoreInterrupts(result);
            break;
        }
    } else {
        switch (result) {
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

        case -2:
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
    }

    if (call && entry->callback)
        entry->callback();
}
