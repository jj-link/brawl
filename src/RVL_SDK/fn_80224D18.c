#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#include <string.h>
#pragma force_active on

typedef struct State {
    s64 time;
    u8 name[34];
    u8 id[4];
    u8 kind;
    u8 sum;
    u8 rest[8];
    int a;
    int b;
    u8 pad[0x8bc - 0x40];
    int result;
    u8 pad2[0x1c];
    int ready;
} State;
typedef struct Entry {
    int active;
    int address;
    short length;
    short pad;
    int offset;
    void (*callback)(int, int);
} Entry;
extern State *lbl_804F6810[];
extern Entry lbl_804F9F70[];
extern u16 lbl_804F9EE0[];
extern void *lbl_805A0C6C;
extern u8 lbl_805A0C70;
extern int fn_8021E394(u8 *, s8);
extern void fn_802252E8(int, void *, unsigned short, unsigned int, void (*)(int, int));
extern void fn_80224CA8(int, int);
extern void fn_80224CE0(int, int);
extern void fn_80224B68(int, int);

int fn_80224D18(int index, int address, short length, int offset, void (*callback)(int, int))
{
    BOOL enabled;
    State *state = lbl_804F6810[index];
    int result;
    int ready;
    enabled = OSDisableInterrupts();
    result = state->result;
    ready = state->ready;
    if (result != -1) {
        if (!ready) {
            result = -2;
        } else if (!lbl_804F9F70[index].active) {
            if (!fn_8021E394((u8 *)state + 0x160, 9)) {
                result = -2;
                goto done;
            }
            {
            u8 i;
            lbl_804F9F70[index].active = 1;
            lbl_804F9F70[index].callback = callback;
            lbl_804F9F70[index].length = length;
            lbl_804F9F70[index].offset = offset + 0x9a;
            lbl_804F9F70[index].address = address;
            memcpy(state->id, lbl_805A0C6C, 4);
            memcpy(state->name, lbl_804F9EE0, 0x22);
            state->time = OSGetTime();
            state->kind = lbl_805A0C70;
            state->sum = 0;
            for (i = 0; i < 47; i++) {
                state->sum += ((u8 *)state)[i];
            }
            state->sum += 0x55;
            state->a = 0;
            state->b = 0;
            fn_802252E8(index, state, 0x10, 0x2a, fn_80224CA8);
            fn_802252E8(index, (u8 *)state + 0x10, 0x10, 0x3a, fn_80224CA8);
            fn_802252E8(index, (u8 *)state + 0x20, 0x10, 0x4a, fn_80224CA8);
            fn_802252E8(index, (u8 *)state + 0x30, 8, 0x5a, fn_80224CA8);
            fn_802252E8(index, state, 0x10, 0x62, fn_80224CE0);
            fn_802252E8(index, (u8 *)state + 0x10, 0x10, 0x72, fn_80224CE0);
            fn_802252E8(index, (u8 *)state + 0x20, 0x10, 0x82, fn_80224CE0);
            fn_802252E8(index, (u8 *)state + 0x30, 8, 0x92, fn_80224B68);
            OSRestoreInterrupts(enabled);
            return 0;
            }
        } else {
            result = -2;
        }
    }
done:
    OSRestoreInterrupts(enabled);
    if (callback) callback(index, result);
    return result;
}