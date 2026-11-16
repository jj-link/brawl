#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct State {
    u8 pad0[0xa0];
    u8 buffers[2][0x60];
    u8 pad1[0x89c - 0x160];
    void (*callback)(int, int);
    void *unk8a0;
    u8 pad2[0x8bc - 0x8a4];
    u32 flag;
    u8 pad3[0x8c1 - 0x8c0];
    u8 unk8c1;
    u8 pad4[0x8c8 - 0x8c2];
    u8 index;
    u8 pad5[0x8e0 - 0x8c9];
    s32 unk8e0;
    u8 pad6[0x974 - 0x8e4];
    u8 *in;
    u32 info;
    s32 status;
    u16 len;
    u8 pad7[0x98d - 0x982];
    u8 unk98d;
} State;

extern State *lbl_804F6810[];
extern char lbl_8047C920[];
extern void fn_8022550C(void *, ...);
extern void fn_80224704(int, void *, u32, u32);
extern void fn_8021E5CC(int, int);
extern void fn_8021F0B4(int, int);
extern void fn_8021F5A0(int, int);
extern void fn_8021F890(int, int, int);
extern void *memcpy(void *, const void *, u32);

void fn_8021FEF0(int channel, u8 *pkt)
{
    u16 infoHi;
    u16 status;
    char *base = lbl_8047C920;
    State *state;
    int enabled;
    u8 *buffer;
    int i, result, mask;
    u16 infoLo;
    u8 len;
    s16 off;

    enabled = OSDisableInterrupts();
    state = lbl_804F6810[(u8)channel];
    buffer = state->buffers[state->index];
    for (i = 0; i < 0x60; i++)
        buffer[i] = 0;

    *(u16 *)buffer = (pkt[1] | (pkt[2] << 8)) & 0x9f1f;
    len = (pkt[3] >> 4) + 1;
    status = pkt[5] | (pkt[4] << 8);

    if (pkt[3] & 0xf) {
        fn_8022550C(base + 0x464);
        state->status = -1;
        if (state->callback != 0) {
            if (state->unk8a0 == 0 || state->unk8a0 != (void *)state->callback)
                state->callback(channel, -3);
            state->callback = 0;
        }
        state->flag = 0;
    }

    infoLo = state->info & 0xffff;
    infoHi = state->info >> 16;
    off = status - infoLo;
    if (status >= infoLo && status <= (s32)(infoLo + state->len)) {
        memcpy(state->in + off, pkt + 6, len);
        if (infoLo + state->len == status + len) {
            fn_8022550C(base + 0x47c, state->info);
            fn_8022550C(base + 0x490, state->len);
            mask = state->status >> 31;
            result = -3 * (state->status < 0);
            fn_8022550C(base + 0x4a0, infoHi);
            fn_8022550C(base + 0x4ac, state->unk98d);
            if (infoHi == 0x4a4) {
                fn_8022550C(base + 0x4b8);
                if ((u8)(state->unk98d + 0xfe) <= 1) {
                    fn_8022550C(base + 0x4d8);
                    fn_8022550C(base + 0x4e4, len, infoLo);
                    fn_80224704(channel, state->in, len, infoLo);
                }
            }
            if ((state->info == 0 && state->unk8e0 == 0) ||
                (state->info == 0x176c && state->unk8e0 == 1))
                fn_8021E5CC(channel, result);
            if (state->info == 0x4a40020)
                fn_8021F0B4(channel, result);
            if (state->info == 0x4a400fa)
                fn_8021F5A0(channel, result);
            if (state->info == 0x2a)
                fn_8021F890(channel, result, 0);
            if (state->info == 0x62)
                fn_8021F890(channel, result, 1);
            if (state->callback != 0) {
                state->callback(channel, result);
                state->callback = 0;
            }
            state->flag = 0;
        }
    } else {
        fn_8022550C(base + 0x500);
    }

    *(signed char *)(buffer + 0x29) = -2;
    buffer[0x28] = state->unk8c1;
    state->index = state->index == 0;
    OSRestoreInterrupts(enabled);
}
