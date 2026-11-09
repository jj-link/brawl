#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef void (*CompletionCallback)(int, int);
typedef void (*OperationCallback)(unsigned int, void *);

typedef struct Entry {
    int active;
    int pad[3];
    CompletionCallback callback;
} Entry;

extern int *lbl_804F6810[];
extern Entry lbl_804F9F70[];
extern void *lbl_805A0C6C;

extern int fn_803F6150(const void *, const void *, unsigned long);
extern int fn_8022521C(int, int, int, void *, OperationCallback);
extern void fn_802249C4(unsigned int, void *);

int fn_802250C8(int index, int arg1, int arg2, void *arg3,
                CompletionCallback callback)
{
    char *state;
    int idx;
    int result;
    BOOL interrupts;
    int missing;
    int ready;

    idx = index;
    state = (char *)lbl_804F6810[index];
    interrupts = OSDisableInterrupts();
    result = *(int *)(state + 0x8BC);
    ready = *(int *)(state + 0x8DC);

    if (result != -1) {
        if (ready == 0) {
            result = -2;
            goto finish;
        }

        if (lbl_804F9F70[idx].active != 0)
            goto busy;

        missing = (*(int *)(state + 0x38) == 0 ||
                   *(int *)(state + 0x3C) == 0);
        result = missing ? 0 : -6;
        if (result != 0)
            goto finish;

        if (fn_803F6150(lbl_805A0C6C, state + 0x2A, 4) == 0) {
            lbl_804F9F70[idx].active = 1;
            lbl_804F9F70[idx].callback = callback;
            OSRestoreInterrupts(interrupts);
            return fn_8022521C(idx, arg1, arg2, (char *)arg3 + 0x9A,
                               fn_802249C4);
        }

        result = -5;
        goto finish;

    busy:
        result = -2;
    }

finish:
    OSRestoreInterrupts(interrupts);
    if (callback != 0)
        callback(idx, result);
    return result;
}
