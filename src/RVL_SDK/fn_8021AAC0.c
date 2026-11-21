#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

typedef struct State {
    u8 pad[0x8AC];
    u8 *buffer;
    s32 index;
    u32 count;
    u32 format;
    s32 status;
} State;

extern State *lbl_804F6810[];
extern u8 lbl_8047C8C0[];
extern s32 fn_8022550C(const char *, ...);

void fn_8021AAC0(s32 channel, void *buf_arg, u32 count_arg)
{
    s32 error;
    State *state;
    s32 enabled;
    u8 *buffer;
    u32 count;
    s32 size;
    s32 n;
    u32 i;
    u32 offset;

    fn_8022550C((const char *)lbl_8047C8C0);
    buffer = buf_arg;
    count = count_arg;
    enabled = OSDisableInterrupts();
    state = lbl_804F6810[channel];

    error = -4;
    if (state->status == -1) {
        error = -1;
    }

    if (state->format <= 2) {
        size = 42;
    } else if (state->format - 3 <= 2) {
        size = 50;
    } else {
        size = 90;
        if (state->format - 6 <= 2) {
            size = 54;
        }
    }

    if (buffer != 0) {
        memset(buffer, 0, size * count);
        i = 0;
        for (n = 0; n < count; n++) {
            (buffer + i)[41] = error;
            i += size;
        }
        state->index = -1;
        state->count = count;
    }

    state->buffer = buffer;
    OSRestoreInterrupts(enabled);
}
