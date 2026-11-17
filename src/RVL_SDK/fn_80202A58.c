#include <types.h>
#include <revolution/AXFX.h>
#pragma force_active on

extern f32 lbl_805A391C;
extern f32 lbl_805A3920;
extern f32 lbl_805A3924;
extern f32 lbl_805A3928;

#define PL(b, o) (*(f32**)((u8*)(b) + (o)))
#define PU(b, o) (*(u32*)((u8*)(b) + (o)))
#define PF(b, o) (*(f32*)((u8*)(b) + (o)))

void fn_80202A58(AXFX_BUFFERUPDATE* update, AXFX_REVERBHI_EXP* fx) {
    s32* out[3];
    f32 res[3];
    f32 tmp[3];
    s32* in[3];
    s32* sendL;
    s32* sendR;
    s32* sendS;
    s32** pin;
    s32** pout;
    u8* b4;
    u8* b12;
    u8* b8;
    f32* pacc;
    f32 lpf, y, allpass, lpfInv, fused, cross, s12, s02, s01;
    u32 i;
    s32 j;
    s32 k;

    if (fx->active != 0) {
        fx->active &= ~2;
        return;
    }

    out[0] = update->left;
    out[1] = update->right;
    out[2] = update->surround;
    if (fx->busIn != NULL) {
        in[0] = fx->busIn->left;
        in[1] = fx->busIn->right;
        in[2] = fx->busIn->surround;
    }
    if (fx->busOut != NULL) {
        sendL = fx->busOut->left;
        sendR = fx->busOut->right;
        sendS = fx->busOut->surround;
    }

    lpfInv = lbl_805A3920 - fx->lpfCoef;
    lpf = fx->lpfCoef;
    fused = lbl_805A3924 * fx->fusedGain;
    cross = lbl_805A3928 * fx->crosstalk;
    allpass = fx->allpassCoef;

    for (i = 0; i < 0x60; i++) {
        pin = in;
        pout = out;
        b4 = (u8*)fx;
        b12 = (u8*)fx;
        b8 = (u8*)fx;
        pacc = tmp;
        for (j = 0; j < 3; j++) {
            f32 x, c0, c1, c2, z, a0, a1, sum, v0, v1;
            f32* line;
            f32* lineB;
            f32* lineC;
            if (fx->busIn != NULL) {
                x = (f32)(**pout + *(*pin)++);
            } else {
                x = (f32)**pout;
            }

            line = PL(b4, 0);
            y = fx->earlyCoef[2] * line[fx->earlyPos[2]] +
                (fx->earlyCoef[0] * line[fx->earlyPos[0]] + fx->earlyCoef[1] * line[fx->earlyPos[1]]);

            if (fx->preDelayLength != 0) {
                line = PL(b4, 0x2C);
                z = line[fx->preDelayPos];
                line[fx->preDelayPos] = x;
            } else {
                z = x;
            }

            sum = lbl_805A391C;
            lineB = PL(b12, 0x44);
            c0 = lineB[fx->combPos[0]];
            lineB[fx->combPos[0]] = z + c0 * fx->combCoef[0];
            sum += c0;

            lineB = PL(b12, 0x48);
            c1 = lineB[fx->combPos[1]];
            lineB[fx->combPos[1]] = z + c1 * fx->combCoef[1];
            sum += c1;

            lineB = PL(b12, 0x4C);
            c2 = lineB[fx->combPos[2]];
            lineB[fx->combPos[2]] = z + c2 * fx->combCoef[2];
            sum += c2;

            lineC = PL(b8, 0x98);
            a0 = lineC[fx->allpassPos[0]];
            v0 = sum + a0 * allpass;
            lineC[fx->allpassPos[0]] = v0;

            lineC = PL(b8, 0x9C);
            a1 = lineC[fx->allpassPos[1]];
            sum = (a0 - v0 * allpass) + a1 * allpass;
            lineC[fx->allpassPos[1]] = sum;

            v1 = lpfInv * (a1 - sum * allpass) + lpf * PF(b4, 0xFC);
            PF(b4, 0xFC) = v1;

            lineC = PL(b4, 0xC8);
            a0 = lineC[PU(b4, 0xD4)];
            v0 = v1 + a0 * allpass;
            lineC[PU(b4, 0xD4)] = v0;
            PU(b4, 0xD4)++;
            *pacc = a0 - v0 * allpass;
            if (PU(b4, 0xD4) >= PU(b4, 0xE0)) {
                PU(b4, 0xD4) = 0;
            }

            *pacc *= fused;
            *pacc += y;

            pin++;
            pout++;
            b4 += 4;
            b12 += 12;
            b8 += 8;
            pacc++;
        }

        s12 = tmp[1] + tmp[2];
        s02 = tmp[0] + tmp[2];
        s01 = tmp[0] + tmp[1];
        res[0] = tmp[0] + s12 * cross;
        res[1] = tmp[1] + s02 * cross;
        res[2] = tmp[2] + s01 * cross;

        *out[0]++ = (s32)(res[0] * fx->outGain);
        *out[1]++ = (s32)(res[1] * fx->outGain);
        *out[2]++ = (s32)(res[2] * fx->outGain);

        if (fx->busOut != NULL) {
            *sendL++ = (s32)(res[0] * fx->sendGain);
            *sendR++ = (s32)(res[1] * fx->sendGain);
            *sendS++ = (s32)(res[2] * fx->sendGain);
        }

        for (k = 0; k < 3; k++) {
            if (++fx->earlyPos[k] >= fx->earlyLength) {
                fx->earlyPos[k] = 0;
            }
        }
        if (fx->preDelayLength != 0) {
            if (++fx->preDelayPos >= fx->preDelayLength) {
                fx->preDelayPos = 0;
            }
        }
        for (k = 0; k < 3; k++) {
            if (++fx->combPos[k] >= fx->combLength[k]) {
                fx->combPos[k] = 0;
            }
        }
        for (k = 0; k < 2; k++) {
            if (++fx->allpassPos[k] >= fx->allpassLength[k]) {
                fx->allpassPos[k] = 0;
            }
        }
    }
}
