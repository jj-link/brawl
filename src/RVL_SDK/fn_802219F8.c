#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

typedef struct ControllerSample {
    u16 buttons;
    s16 accelX;
    s16 accelY;
    s16 accelZ;
    u8 padding08[0x20];
    u8 extensionType;
    s8 error;
    u16 extensionButtons;
    s16 stickX;
    s16 stickY;
    s16 substickX;
    s16 substickY;
    u8 triggerL;
    u8 triggerR;
    u8 padding36[0x2a];
} ControllerSample;

typedef struct ControllerState {
    u8 padding000[0xa0];
    ControllerSample samples[2];
    u8 padding160[0x6e0];
    int extensionEnabled;
    u8 padding844[4];
    int flag848;
    u8 padding84c[0x28];
    s16 accelX;
    s16 accelY;
    s16 accelZ;
    u8 padding87a[8];
    s16 centerX;
    u8 padding884[4];
    s16 centerY;
    u8 padding88a[4];
    s16 centerSubX;
    s16 extensionAccelY;
    s16 extensionAccelZ;
    s16 centerSubY;
    u8 padding896[4];
    u8 centerTriggerL;
    u8 centerTriggerR;
    u8 padding89c[0x1c];
    int status;
    u8 padding8bc[5];
    u8 extensionType;
    u8 extensionFormat;
    u8 padding8c3[5];
    u8 currentSample;
    u8 padding8c9[0x48];
    u8 calibrated;
} ControllerState;

extern ControllerState *lbl_804F6810[];
extern u8 lbl_804F9F58[];
extern u8 lbl_8047C9A0[];
extern u8 lbl_805A0C8C[4];

extern void fn_80224704(u8, const void *, int, int);
extern int fn_803F6150(const void *, const void *, unsigned long);

void fn_802219F8(u8 channel, u8 *data)
{
    ControllerState *state = lbl_804F6810[channel];
    ControllerSample *sample = &state->samples[state->currentSample];
    ControllerSample *extension;
    int i;
    int status;
    s16 x, y;
    u32 interrupts;
    u8 *base;

    base = (u8 *)sample;
    for (i = 0; i < sizeof(ControllerSample); i += 8) {
        base[i + 0] = 0;
        base[i + 1] = 0;
        base[i + 2] = 0;
        base[i + 3] = 0;
        base[i + 4] = 0;
        base[i + 5] = 0;
        base[i + 6] = 0;
        base[i + 7] = 0;
    }

    sample->buttons = (data[1] | (data[2] << 8)) & 0x9f1f;
    status = state->status;
    if (status == 0 || (u32)status == 1 || (u32)status == 3 ||
        (u32)status == 4 || (u32)(status - 6) <= 1) {
        sample->error = 0;
    } else {
        sample->error = -4;
    }

    sample->extensionType = state->extensionType;
    state->flag848 = (data[1] >> 7) & 1;
    sample->accelX = (s16)((s16)((s16)(data[3] << 2) & ~3) |
                             ((data[1] >> 5) & 3)) - state->accelX;
    sample->accelY = (s16)((s16)((s16)(data[4] << 2) & ~3) |
                             (s16)((data[2] >> 4) & 2)) - state->accelY;
    sample->accelZ = (s16)((s16)((s16)(data[5] << 2) & ~3) |
                             (s16)((data[2] >> 5) & 2)) - state->accelZ;

    memcpy(lbl_804F9F58, data + 6, 0x10);
    fn_80224704(channel, data + 6, 0x10, 0);

    if (state->extensionEnabled) {
        if (state->extensionType == 1) {
            extension = &state->samples[state->currentSample];
            ((u8 *)extension)[0x30] = data[6];
            ((u8 *)extension)[0x31] = data[7];
            {
                s16 high = (s16)(data[8] * 4) & ~3;
                s16 low = (s16)(data[11] >> 2) & 3;
                extension->extensionButtons = (s16)(high | low) - state->centerSubX;
            }
            {
                s16 high = (s16)(data[9] * 4) & ~3;
                s16 low = (s16)(data[11] >> 4) & 3;
                extension->stickX = (s16)(high | low) - state->extensionAccelY;
            }
            extension->stickY =
                (s16)((s16)((s16)(data[10] << 2) & ~3) |
                      (data[11] >> 6)) - state->extensionAccelZ;
            extension->buttons |= (~data[11] & 3) << 13;

            if (!state->calibrated) {
                state->calibrated = 1;
                state->centerX = (s8)((u8 *)extension)[0x30];
                state->centerY = (s8)((u8 *)extension)[0x31];
            }

            x = ((u8 *)extension)[0x30] - (u8)state->centerX;
            y = ((u8 *)extension)[0x31] - (u8)state->centerY;
            if (x < -128)
                ((s8 *)extension)[0x30] = -128;
            else if (x > 127)
                ((u8 *)extension)[0x30] = 127;
            else
                ((u8 *)extension)[0x30] = x;

            if (y < -128)
                ((s8 *)extension)[0x31] = -128;
            else if (y > 127)
                ((u8 *)extension)[0x31] = 127;
            else
                ((u8 *)extension)[0x31] = y;
        } else if (state->extensionType == 2) {
            switch (state->extensionFormat) {
            case 1:
                extension = &state->samples[state->currentSample];
                extension->stickX = (s16)((data[6] & 0x3f) << 4) - 512;
                extension->stickY = (s16)((data[7] & 0x3f) << 4) - 512;
                {
                    s16 a = (s16)(data[7] >> 5) & 6;
                    s16 b = (s16)(data[8] >> 7);
                    s16 c = (s16)(data[6] >> 3) & 0x18;
                    s16 d = c | a | b;
                    extension->substickX = (s16)(d << 5) - 512;
                }
                extension->substickY = (s16)((data[8] & 0x1f) << 5) - 512;
                {
                    s16 a = data[8] >> 2;
                    s16 b = data[9] >> 5;
                    extension->triggerL = ((a & 0x18) | (b & ~0x18)) << 3;
                }
                extension->triggerR = (data[9] & 0x1f) << 3;
                extension->extensionButtons =
                    (data[11] | (data[10] << 8)) ^ 0xffff;
                break;

            case 2:
                extension = &state->samples[state->currentSample];
                {
                    s16 high = (s16)(data[6] * 4) & ~3;
                    s16 low = data[10] & 3;
                    extension->stickX = (s16)(high | low) - 512;
                }
                {
                    s16 high = (s16)(data[7] * 4) & ~3;
                    s16 low = (s16)(data[10] >> 2) & 3;
                    extension->substickX = (s16)(high | low) - 512;
                }
                {
                    s16 high = (s16)(data[8] * 4) & ~3;
                    s16 low = (s16)(data[10] >> 4) & 3;
                    extension->stickY = (s16)(high | low) - 512;
                }
                {
                    s16 high = (s16)(data[9] * 4) & ~3;
                    s16 low = data[10] >> 6;
                    extension->substickY = (s16)(high | low) - 512;
                }
                extension->triggerL = data[11];
                extension->triggerR = data[12];
                extension->extensionButtons =
                    (data[14] | (data[13] << 8)) ^ 0xffff;
                break;

            case 3:
                extension = &state->samples[state->currentSample];
                extension->stickX = (s16)((s16)(data[6] & 0xffff) * 4) - 512;
                extension->substickX = (s16)((s16)(data[7] & 0xffff) * 4) - 512;
                extension->stickY = (s16)((s16)(data[8] & 0xffff) * 4) - 512;
                extension->substickY = (s16)((s16)(data[9] & 0xffff) * 4) - 512;
                extension->triggerL = data[10];
                extension->triggerR = data[11];
                extension->extensionButtons =
                    (data[13] | (data[12] << 8)) ^ 0xffff;
                break;
            }

            if (!state->calibrated) {
                state->calibrated = 1;
                state->centerX = extension->stickX;
                state->centerY = extension->stickY;
                state->centerSubX = extension->substickX;
                state->centerSubY = extension->substickY;
                state->centerTriggerL = extension->triggerL;
                state->centerTriggerR = extension->triggerR;
            }

            x = extension->stickX - state->centerX;
            y = extension->stickY - state->centerY;
            if (x < -512)
                extension->stickX = -512;
            else if (x > 511)
                extension->stickX = 511;
            else
                extension->stickX = x;

            if (y < -512)
                extension->stickY = -512;
            else if (y > 511)
                extension->stickY = 511;
            else
                extension->stickY = y;

            x = extension->substickX - state->centerSubX;
            y = extension->substickY - state->centerSubY;
            if (x < -512)
                extension->substickX = -512;
            else if (x > 511)
                extension->substickX = 511;
            else
                extension->substickX = x;

            if (y < -512)
                extension->substickY = -512;
            else if (y > 511)
                extension->substickY = 511;
            else
                extension->substickY = y;

            x = extension->triggerL - state->centerTriggerL;
            y = extension->triggerR - state->centerTriggerR;
            if (x < 0)
                extension->triggerL = 0;
            else
                extension->triggerL = x;
            if (y < 0)
                extension->triggerR = 0;
            else
                extension->triggerR = y;

            if (lbl_805A0C8C[channel]) {
                extension->substickX = 0;
                extension->substickY = 0;
                extension->triggerL = 0;
                extension->triggerR = 0;
            }
        }

        if (fn_803F6150(lbl_804F9F58, lbl_8047C9A0, 0x10) == 0 &&
            sample->error == 0) {
            sample->error = -7;
        }
    }

    interrupts = OSDisableInterrupts();
    state->currentSample = (state->currentSample == 0);
    OSRestoreInterrupts(interrupts);
}
