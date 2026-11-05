#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_805A2368;

struct Obj {
    u8 flagHi : 3;
    u8 flagLo : 5;
    u8 pad1[3];
    u32 w4;
    u32 w8;
    u32 wC;
    u32 arr[81];
    u32 w154;
    u32 w158;
    u32 w15C;
    u32 w160;
    u32 w164;
    s32 w168;
    u8 b16C;
    u8 pad2[3];
    f32 f170;
    u8 b174;
    u8 pad3[3];
    s32 w178;
};

void fn_800DD564(void* self) {
    Obj* o = (Obj*)self;
    u32* p = (u32*)self;
    o->w8 = 0;
    u32 idx = 0;
    o->wC = 0;
    for (int i = 0; i < 2; i++) {
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p[14] = 0;
        p[15] = 0;
        p[16] = 0;
        p[17] = 0;
        p[18] = 0;
        p[19] = 0;
        p[20] = 0;
        p[21] = 0;
        p[22] = 0;
        p[23] = 0;
        p[24] = 0;
        p[25] = 0;
        p[26] = 0;
        p[27] = 0;
        p[28] = 0;
        p[29] = 0;
        p[30] = 0;
        p[31] = 0;
        p[32] = 0;
        p[33] = 0;
        p[34] = 0;
        p[35] = 0;
        p[36] = 0;
        p[37] = 0;
        p[38] = 0;
        p[39] = 0;
        p[40] = 0;
        p[41] = 0;
        p[42] = 0;
        p[43] = 0;
        idx += 40;
        p += 40;
    }
    o->arr[idx] = 0;
    o->w154 = 0;
    o->w158 = 0;
    o->w15C = 0;
    o->w160 = 0;
    o->flagHi = 0;
    o->w4 = 0;
    o->w164 = 0;
    o->w168 = -1;
    o->b16C = 1;
    o->f170 = lbl_805A2368;
    o->b174 = 0;
    o->w178 = -1;
}
}
