#pragma force_active on
#include <types.h>

typedef struct Pkt {
    u8 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
} Pkt;

extern void fn_80242908(u8 *);

void fn_80245D9C(Pkt *arg0, int arg1, u8 arg2, u8 *arg3, int arg4) {
    u8 *dst;
    int count;
    int k;

    arg0->unk4 = 0;
    arg0->unk8 = 5;
    arg0->unk9 = 0xC;
    if (arg1 != 0) {
        arg0->unk2 = arg4 + 5;
        dst = (u8 *)arg0 + 0xD;
        arg0->unkA = arg4 + 2;
        arg0->unkB = arg1;
        arg0->unkC = arg2;
        if (arg2 == 1) {
            count = (u8)(arg4 - 6);
            dst[0] = arg3[2];
            dst[1] = arg3[1];
            dst[2] = arg3[0];
            dst[3] = arg3[5];
            dst[4] = arg3[4];
            dst[5] = arg3[3];
            arg3 += 6;
            dst += 6;
        } else if (arg2 == 2) {
            count = (u8)(arg4 - 6);
            dst[0] = arg3[5];
            dst[1] = arg3[4];
            dst[2] = arg3[3];
            dst[3] = arg3[2];
            dst[4] = arg3[1];
            dst[5] = arg3[0];
            arg3 += 6;
            dst += 6;
        } else {
            count = arg4;
        }
        if (count != 0) {
            for (k = 0; k < count; k++) {
                *dst++ = arg3[k];
            }
        }
    } else {
        arg0->unk2 = 4;
        arg0->unkA = 1;
        arg0->unkB = arg1;
    }
    fn_80242908((u8 *)arg0);
}