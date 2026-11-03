#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct State {
    u8 pad0[0xa0];
    u8 buffers[2][0x60];
    u8 pad160[0x73c];
    void (*callback)(int, int);
    u8 pad8a0[0x1c];
    int pending;
    u8 pad8c0;
    u8 value;
    u8 pad8c2[6];
    u8 index;
    u8 pad8c9[0xbe];
    u8 sequence;
} State;
extern State *lbl_804F6810[];
extern char lbl_8047C920[];
extern void fn_8022550C(void *, ...);
void fn_802202F8(int channel, u8 *data)
{
    char *base = lbl_8047C920;
    State *state;
    int enabled;
    u8 *buffer;
    u8 sequence, error;
    int result;
    int i;
    enabled = OSDisableInterrupts();
    fn_8022550C(base + 0x520);
    state = lbl_804F6810[(u8)channel];
    buffer = state->buffers[state->index];
    for (i = 0; i < 0x60; i++)
        buffer[i] = 0;
    *(u16 *)buffer = (data[1] | (data[2] << 8)) & 0x9f1f;
    sequence = data[3];
    error = data[4];
    fn_8022550C(base + 0x530, sequence, error);
    result = -3 * !(error == 0);
    *(signed char *)(buffer + 0x29) = -2;
    buffer[0x28] = state->value;
    if (error != 0)
        fn_8022550C(base + 0x55c, sequence, error);
    if (state->sequence == sequence) {
        if (state->callback != 0) {
            state->callback(channel, result);
            state->callback = 0;
        }
        state->pending = 0;
    } else {
        fn_8022550C(base + 0x58c);
    }
    state->index = state->index == 0;
    OSRestoreInterrupts(enabled);
}