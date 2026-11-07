#include <revolution/OS/OSInterrupt.h>
#include <string.h>

#pragma force_active on

typedef struct Buffer {
    unsigned char bytes[0x60];
} Buffer;

typedef struct State {
    unsigned char pad0[0xa0];
    Buffer buffers[2];
    unsigned char pad160[0x758];
    unsigned int mode;
    unsigned char pad8bc[0xc];
    unsigned char active;
} State;

extern State *lbl_804F6810[];

void fn_8021A920(int index, unsigned char *out)
{
    unsigned char *data;
    State *state;
    unsigned int mode;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    state = lbl_804F6810[index];
    data = state->buffers[(unsigned char)(state->active == 0)].bytes;

    switch ((signed char)data[0x29]) {
    case 0:
        mode = state->mode;
        if (mode <= 2)
            memcpy(out, data, 0x2a);
        else if (mode - 3 <= 2)
            memcpy(out, data, 0x32);
        else if (mode - 6 <= 2)
            memcpy(out, data, 0x36);
        else
            memcpy(out, data, 0x5a);
        break;

    case -2:
    case -7:
        memcpy(out, data, 0x2a);
        break;

    default:
        mode = state->mode;
        if (mode <= 2)
            memset(out, 0, 0x2a);
        else if (mode - 3 <= 2)
            memset(out, 0, 0x32);
        else if (mode - 6 <= 2)
            memset(out, 0, 0x36);
        else
            memset(out, 0, 0x5a);
        out[0x29] = data[0x29];
        break;
    }

    OSRestoreInterrupts(enabled);
}
