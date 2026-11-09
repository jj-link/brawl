#include <string.h>
#include <revolution/OS/OSInterrupt.h>
#include <types.h>
#pragma force_active on

typedef void (*Callback)(int, int);

typedef struct Msg {
    int type, a, b, c, d, e;
    short f, g;
    int h, i, j, k;
    Callback cb;
} Msg;

typedef struct State {
    char pad[0x160];
    s8 head, tail;
    char pad2[2];
    void *buf;
    int size;
    char pad3[0x750];
    int status;
    char pad4[0x1c];
    int active;
} State;

extern State *lbl_804F6810[];

int fn_8021A68C(int index, int value, Callback callback)
{
    int result;
    int active;
    int enabled;
    State *state;

    state = lbl_804F6810[index];
    enabled = OSDisableInterrupts();
    result = state->status;
    active = state->active;
    OSRestoreInterrupts(enabled);

    if (result != -1) {
        if (active == 0) {
            result = -2;
        } else {
            Msg out, m;
            int ok;
            s8 cnt;

            m.type = 0x11;
            m.g = 1;
            *(u8 *)&m.a = (value & 15) << 4;
            m.cb = callback;
            out = m;

            result = OSDisableInterrupts();
            {
                int en2 = OSDisableInterrupts();
                cnt = state->tail - state->head;
                if (cnt < 0)
                    cnt += state->size;
                OSRestoreInterrupts(en2);
            }

            if ((u32)(state->size - 1) == (u32)cnt) {
                OSRestoreInterrupts(result);
                ok = 0;
            } else {
                memset((char *)state->buf + state->tail * 0x30, 0, 0x30);
                memcpy((char *)state->buf + state->tail * 0x30, &out, 0x30);
                {
                    int n = state->size - 1;
                    state->tail = state->tail == n ? 0 : state->tail + 1;
                }
                OSRestoreInterrupts(result);
                ok = 1;
            }
            result = ok ? 0 : -2;
        }
    }

    if (result && callback)
        callback(index, result);
    return result;
}
