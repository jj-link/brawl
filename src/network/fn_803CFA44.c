#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state;
    int previousState;
    int error;
} State;

typedef struct {
    void (*fn)(void);
    char pad[0x1d4];
    unsigned char flag;
} Entry;

extern int fn_8020B8A0(int);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern int fn_803CD2FC(void);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

void fn_803CFA44(int arg0, int arg1) {
    Entry *entry;
    int enabled;

    entry = fn_803CD3B4(*(int *)((char *)fn_8020B8A0(arg1) + 4));
    switch (arg0) {
    case 0: {
        int enabled;
        int prev;
        entry->flag = 0;
        enabled = OSDisableInterrupts();
        fn_803CD318(0);
        prev = fn_803CD324()->previousState;
        fn_803CD324()->state = prev;
        prev = fn_803CD324()->previousState;
        fn_803CD324()->error = prev;
        OSRestoreInterrupts(enabled);
        break;
    }
    case -3:
    case -4:
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
    case -128:
    case -64:
    case -8:
    case -2:
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

    if (fn_803CD2FC() == 0) {
        if (entry->fn != 0) {
            entry->fn();
        }
    }
}
