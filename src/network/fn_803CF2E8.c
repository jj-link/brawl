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
    void *buf;
    unsigned int size;
} Entry;

extern int fn_8020B8A0(int);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern void *memset(void *, int, unsigned long);

void fn_803CF2E8(int arg0, int arg1) {
    Entry *entry;
    int doClear;
    BOOL enabled;

    entry = fn_803CD3B4(*(int *)((char *)fn_8020B8A0(arg1) + 4));
    doClear = 0;
    if (arg0 >= 0) {
        if ((unsigned int)arg0 > entry->size) {
            doClear = 1;
            switch (fn_803CD324()->state) {
            case 0:
            case 6: {
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 3;
                fn_803CD324()->error = 0;
                OSRestoreInterrupts(enabled);
                break;
            }
            }
        } else if ((unsigned int)arg0 == entry->size) {
            switch (fn_803CD324()->state) {
            case 0:
            case 6: {
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 0;
                fn_803CD324()->error = 0;
                OSRestoreInterrupts(enabled);
                break;
            }
            }
        } else {
            doClear = 1;
            switch (fn_803CD324()->state) {
            case 0:
            case 6: {
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 3;
                fn_803CD324()->error = 0;
                OSRestoreInterrupts(enabled);
                break;
            }
            }
        }
    } else {
        doClear = 1;
        switch (arg0) {
        case -1:
        case -3:
        case -4:
        case -5:
        case -15:
            switch (fn_803CD324()->state) {
            case 0:
            case 6: {
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 2;
                fn_803CD324()->error = arg0;
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
                enabled = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 5;
                fn_803CD324()->error = arg0;
                OSRestoreInterrupts(enabled);
                break;
            }
            }
            break;
        }
    }

    if (doClear != 0) {
        memset(entry->buf, 0, entry->size);
    }
    if (entry->fn != 0) {
        entry->fn();
    }
}
