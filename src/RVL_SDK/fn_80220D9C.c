#include <types.h>
#include <revolution/os/OSInterrupt.h>
#include <string.h>
#pragma force_active on

typedef struct Report {
    u16 buttons;
    u8 pad02[0x26];
    u8 extension;
    s8 error;
    u16 extButtons;
    s16 x;
    s16 y;
    s16 rx;
    s16 ry;
    u8 triggerL;
    u8 triggerR;
    u8 pad36[0x2a];
} Report;

typedef struct State {
    u8 pad000[0xa0];
    Report reports[2];
    u8 pad160[0x6e0];
    int enabled;
    u8 pad844[4];
    int flag;
    u8 pad84c[0x36];
    s16 centerX;
    u8 pad884[4];
    s16 centerY;
    u8 pad88a[4];
    s16 centerRX;
    s16 centerAccelY;
    s16 centerAccelZ;
    s16 centerRY;
    u8 pad896[4];
    u8 centerL;
    u8 centerR;
    u8 pad89c[0x1c];
    u32 status;
    u8 pad8bc[5];
    u8 extension;
    u8 format;
    u8 pad8c3[5];
    u8 index;
    u8 pad8c9[0x48];
    u8 calibrated;
} State;

extern State *lbl_804F6810[];
extern u8 lbl_804F9F58[];
extern u8 lbl_8047C9A0[];
extern u8 lbl_805A0C8C[4];

extern void fn_80224704(u8, void *, int, int);
extern int fn_803F6150(const void *, const void *, unsigned long);

void fn_80220D9C(u8 channel, u8 *data)
{
    State *state;
    Report *report;
    Report *ext;
    int enabled;
    int i;
    int j;
    s16 a, b;

    enabled = OSDisableInterrupts();
    state = lbl_804F6810[channel];
    report = &state->reports[state->index];

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 8; j++)
            ((u8 *)report)[i * 8 + j] = 0;
    }

    report->buttons = (data[1] | (data[2] << 8)) & 0x9f1f;
    if (state->status == 0 || state->status == 3 || state->status == 6)
        report->error = 0;
    else
        report->error = -4;

    report->extension = state->extension;
    state->flag = (data[1] >> 7) & 1;
    memcpy(lbl_804F9F58, data + 3, 8);
    fn_80224704(channel, data + 3, 8, 0);

    if (state->enabled != 0) {
        if (state->extension == 1) {
            ext = &state->reports[state->index];
            ((u8 *)ext)[0x30] = data[3];
            ((u8 *)ext)[0x31] = data[4];
            ext->extButtons = (s16)((s16)((s16)(data[5] << 2) & ~3) |
                                             ((s16)(data[8] >> 2) & 3)) - state->centerRX;
            ext->x = (s16)((s16)((s16)(data[6] << 2) & ~3) |
                                   ((s16)(data[8] >> 4) & 3)) - state->centerAccelY;
            ext->y = (s16)((s16)((s16)(data[7] << 2) & ~3) |
                                   (data[8] >> 6)) - state->centerAccelZ;
            ext->buttons |= (~data[8] & 3) << 13;

            if (state->calibrated == 0) {
                state->calibrated = 1;
                state->centerX = (s8)((u8 *)ext)[0x30];
                state->centerY = (s8)((u8 *)ext)[0x31];
            }

            a = ((u8 *)ext)[0x30] - (u8)state->centerX;
            b = ((u8 *)ext)[0x31] - (u8)state->centerY;
            if (a < -128)
                ((s8 *)ext)[0x30] = -128;
            else if (a > 127)
                ((s8 *)ext)[0x30] = 127;
            else
                ((s8 *)ext)[0x30] = a;

            if (b < -128)
                ((s8 *)ext)[0x31] = -128;
            else if (b > 127)
                ((s8 *)ext)[0x31] = 127;
            else
                ((s8 *)ext)[0x31] = b;
        } else if (state->extension == 2) {
            switch (state->format) {
            case 1:
                ext = &state->reports[state->index];
                ext->x = (s16)((data[3] & 0x3f) << 4) - 0x200;
                ext->y = (s16)((data[4] & 0x3f) << 4) - 0x200;
                {
                    s16 a = (s16)(data[4] >> 5) & 6;
                    s16 b = (s16)(data[5] >> 7);
                    s16 c = (s16)(data[3] >> 3) & 0x18;
                    s16 d = c | a | b;
                    ext->rx = (s16)(d << 5) - 0x200;
                }
                ext->ry = (s16)((data[5] & 0x1f) << 5) - 0x200;
                ext->triggerL = ((((u8)(data[5] >> 2) & 0x18) | (data[6] >> 5)) & 0x1f) << 3;
                ext->triggerR = (data[6] & 0x1f) << 3;
                ext->extButtons = (data[8] | (data[7] << 8)) ^ 0xffff;
                break;
            case 2:
                ext = &state->reports[state->index];
                ext->x = (s16)((s16)((s16)(data[3] << 2) & ~3) |
                                      (data[7] & 3)) - 0x200;
                ext->rx = (s16)((s16)((s16)(data[4] << 2) & ~3) |
                                       ((s16)(data[7] >> 2) & 3)) - 0x200;
                ext->y = (s16)((s16)((s16)(data[5] << 2) & ~3) |
                                      ((s16)(data[7] >> 4) & 3)) - 0x200;
                ext->ry = (s16)((s16)((s16)(data[6] << 2) & ~3) |
                                       (data[7] >> 6)) - 0x200;
                ext->triggerL = data[8];
                ext->triggerR = data[9];
                ext->extButtons = (data[11] | (data[10] << 8)) ^ 0xffff;
                break;
            case 3:
                ext = &state->reports[state->index];
                ext->x = (s16)((s16)((s8)data[3] & 0xff) << 2) - 0x200;
                ext->rx = (s16)((s16)((s8)data[4] & 0xff) << 2) - 0x200;
                ext->y = (s16)((s16)((s8)data[5] & 0xff) << 2) - 0x200;
                ext->ry = (s16)((s16)((s8)data[6] & 0xff) << 2) - 0x200;
                ext->triggerL = data[7];
                ext->triggerR = data[8];
                ext->extButtons = (data[10] | (data[9] << 8)) ^ 0xffff;
                break;
            }

            if (state->calibrated == 0) {
                state->calibrated = 1;
                state->centerX = ext->x;
                state->centerY = ext->y;
                state->centerRX = ext->rx;
                state->centerRY = ext->ry;
                state->centerL = ext->triggerL;
                state->centerR = ext->triggerR;
            }

            a = ext->x - state->centerX;
            b = ext->y - state->centerY;
            if (a < -512)
                ext->x = -512;
            else if (a > 511)
                ext->x = 511;
            else
                ext->x = a;
            if (b < -512)
                ext->y = -512;
            else if (b > 511)
                ext->y = 511;
            else
                ext->y = b;

            a = ext->rx - state->centerRX;
            b = ext->ry - state->centerRY;
            if (a < -512)
                ext->rx = -512;
            else if (a > 511)
                ext->rx = 511;
            else
                ext->rx = a;
            if (b < -512)
                ext->ry = -512;
            else if (b > 511)
                ext->ry = 511;
            else
                ext->ry = b;

            a = ext->triggerL - state->centerL;
            b = ext->triggerR - state->centerR;
            if (a < 0)
                ext->triggerL = 0;
            else
                ext->triggerL = a;
            if (b < 0)
                ext->triggerR = 0;
            else
                ext->triggerR = b;

            if (lbl_805A0C8C[channel] != 0) {
                ext->rx = 0;
                ext->ry = 0;
                ext->triggerL = 0;
                ext->triggerR = 0;
            }
        }

        if (fn_803F6150(lbl_804F9F58, lbl_8047C9A0, 8) == 0 &&
            report->error == 0)
            report->error = -7;
    }

    state->index = state->index == 0;
    OSRestoreInterrupts(enabled);
}
