#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct State {
    unsigned char pad0[0x8b8];
    unsigned int mode;
    unsigned char pad8bc[0xc];
    unsigned char active;
    unsigned char pad8c9[0x48];
    unsigned char flag;
    unsigned short count;
} State;

extern State *lbl_804F6810[];

void fn_80217EA4(int index)
{
    State *state = lbl_804F6810[index];
    int result = -1;
    BOOL enabled = OSDisableInterrupts();
    int mode = state->mode;
    unsigned char *data = (unsigned char *)state + (unsigned char)(state->active == 0) * 0x60;

    if ((unsigned int)(mode - 3) <= 2 && *(unsigned short *)(data + 0xa0) == 0x1c10)
        result = 1;
    if ((unsigned int)(mode - 6) <= 2) {
        if (*(unsigned short *)(data + 0xa0) == 0x1c10)
            result = 1;
        if (*(signed char *)(data + 0xc9) != 0)
            result = 0;
        else if (*(unsigned short *)(data + 0xca) == 0x1450)
            result = 1;
    }
    if (result < 0)
        state->count = 0;
    else
        state->count += result;
    OSRestoreInterrupts(enabled);
    if (state->count > 0x258) {
        State *other = lbl_804F6810[index];
        enabled = OSDisableInterrupts();
        other->flag = 0;
        OSRestoreInterrupts(enabled);
    }
}