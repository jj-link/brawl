#include <types.h>
#include <revolution/GX.h>
#include <math.h>
#pragma force_active on

extern const f32 lbl_805A2F60;
extern const f32 lbl_805A2F64;
extern const f32 lbl_805A2F6C;
extern const f32 lbl_805A2F70;
extern const f32 lbl_805A2F74;

struct Vec2Copy {
    f32 x;
    f32 y;
};

static inline int sameCache(u8* p, u8* e, f32 a, f32 b, f32 c, f32 d,
                            s32 x, s32 y, Vec2Copy trans, f32 angle,
                            Vec2Copy scale)
{
    int same;
    if (*(u8**)(p + 4) != e || *(f32*)(p + 8) != a ||
        *(f32*)(p + 0xC) != b || *(f32*)(p + 0x10) != c ||
        *(f32*)(p + 0x14) != d || *(s32*)(p + 0x18) != x ||
        *(s32*)(p + 0x1C) != y || *(f32*)(p + 0x20) != scale.x ||
        *(f32*)(p + 0x24) != scale.y || *(f32*)(p + 0x28) != angle ||
        *(f32*)(p + 0x2C) != trans.x || *(f32*)(p + 0x30) != trans.y)
        same = 0;
    else
        same = 1;
    return same;
}

struct Arg3 {
    u8 padding[0x30];
    f32 matrix[12];
};

static inline void updateCache(u8* p, u8* e, f32 a, f32 b, f32 c, f32 d,
                               s32 x, s32 y, Vec2Copy scale, f32 angle,
                               Vec2Copy trans)
{
    *(u8**)(p + 4) = e;
    *(f32*)(p + 8) = a;
    *(f32*)(p + 0xC) = b;
    *(f32*)(p + 0x10) = c;
    *(f32*)(p + 0x14) = d;
    *(s32*)(p + 0x18) = x;
    *(s32*)(p + 0x1C) = y;
    *(f32*)(p + 0x20) = scale.x;
    *(f32*)(p + 0x24) = scale.y;
    *(f32*)(p + 0x28) = angle;
    *(f32*)(p + 0x2C) = trans.x;
    *(f32*)(p + 0x30) = trans.y;
}

extern "C" {
void fn_801EC158(void* m);
void fn_801EC1B8(void* a, void* b, void* c);
void fn_801F28F0(void* p, void* src, u16 w, u16 h, u32 t, s32 a, s32 b, u32 c);
void fn_801F2AFC(void* p, void* src, u16 w, u16 h, u32 t, s32 a, s32 b, u32 c, s32 d);
void fn_801F2B44(void* p, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f, f32 g, f32 h);
void fn_801F2FB0(void* p, s32 a);
void fn_801F3004(void* p, void* src, u32 a, u16 b);
void fn_801F302C(void* p, s32 a);
void fn_801F5304(void* m, s32 a, s32 b);
}

extern "C" s32 fn_8017592C(void* arg0, void* arg1, u16* arg2, Arg3* arg3, s32 arg4)
{
    f32 m90[12];
    f32 m60[12];
    u8 sp30[0x10];
    u8 sp40[0x20];
    u8* p31;
    u8* p30;
    s32 sh4;
    s32 sh2;
    u8* p27;
    u8* p26;
    u8* e;
    s32 r24, r23;
    s32 ret;
    s32 i;
    f32 f29, f28, f27, f26;
    f32 f25, f24, f23, f22, f21;

    p31 = (u8*)arg0;
    p30 = (u8*)arg1;
    p27 = (u8*)arg1;
    p26 = (u8*)arg0;
    ret = 0;
    i = 0;
    sh4 = 0;
    sh2 = 0;

    do {
        f21 = lbl_805A2F6C;
        f25 = lbl_805A2F64;
        f22 = lbl_805A2F70;
        f23 = lbl_805A2F74;
        f24 = lbl_805A2F60;
        s32 var_r3;
        s32 shift = sh4 + 2;

        if (*(s32*)(p31 + 0xB0) >= 0) {
            e = *(u8**)(p30 + 0x88);
            if (e != NULL) {
                u16 hw = *(u16*)((u8*)arg1 + 0x94);
                var_r3 = 1;
                r24 = (hw >> sh4) & 3;
                if (r24 == 2) var_r3 = 2;
                u8 bw = *(u8*)((u8*)arg1 + 0x96);
                u32 r6 = (bw >> sh2) & 3;
                if (r6 == 1 || r6 == 3) var_r3 -= var_r3 * 2;
                f29 = (f32)var_r3;
                r23 = (hw >> shift) & 3;
                s32 var_r3_2 = 1;
                if (r23 == 2) var_r3_2 = 2;
                if (r6 == 2 || (u8)r6 == 3) var_r3_2 -= var_r3_2 * 2;
                f28 = (f32)var_r3_2;
                s32 var_r0 = 0;
                if (r6 == 1 || r6 == 3) var_r0 = 1;
                if (r24 == 2) var_r0 *= 2;
                f27 = (f32)var_r0;
                s32 var_r0_2 = 0;
                if (r6 == 2 || (u8)r6 == 3) var_r0_2 = 1;
                if (r23 == 2) var_r0_2 *= 2;
                f26 = (f32)var_r0_2;

                s32 upd = arg4;
                if (arg4 == 0) {
                    s32 same = sameCache(
                        p26, e, f29, f28, f27, f26, r24, r23,
                        *(Vec2Copy*)(p27 + 0x70), *(f32*)(p30 + 0x64),
                        *(Vec2Copy*)(p27 + 0x4C));
                    upd = (same == 0);
                }

                if (upd != 0) {
                    ret = 1;
                    updateCache(p26, e, f29, f28, f27, f26, r24, r23,
                                *(Vec2Copy*)(p27 + 0x4C), *(f32*)(p30 + 0x64),
                                *(Vec2Copy*)(p27 + 0x70));

                    s32 t = *(u8*)(e + 0xC);
                    switch (t) {
                    case 8:
                    case 9:
                    case 10:
                        fn_801F3004(sp30, *(void**)(e + 0x1C),
                                    *(u8*)(e + 0xD), *(u16*)(e + 0xE));
                        fn_801F302C(sp30, *(s32*)(p31 + 0xB0));
                        fn_801F2AFC(sp40, *(void**)(e + 0x18),
                                    *(u16*)(e + 4), *(u16*)(e + 6),
                                    (u32)t, r24, r23,
                                    (u32)(1 - *(u8*)(e + 0x14)) >> 31,
                                    *(s32*)(p31 + 0xB0));
                        break;
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 14:
                        fn_801F28F0(sp40, *(void**)(e + 0x18),
                                    *(u16*)(e + 4), *(u16*)(e + 6),
                                    (u32)t, r24, r23,
                                    (u32)(1 - *(u8*)(e + 0x14)) >> 31);
                        break;
                    }

                    u8 b14 = *(u8*)(e + 0x14);
                    f32 level = f21 + (f32)b14;
                    fn_801F2B44(sp40, (u32)b14 > 1 ? 5 : 1, 1, 0, 0, 0,
                                lbl_805A2F64, level, f25);
                    fn_801F2FB0(sp40, *(s32*)(p31 + 0xB0));

                    fn_801EC158(m90);
                    fn_801EC158(m60);
                    m60[3] = *(f32*)(p27 + 0x70);
                    m60[7] = *(f32*)(p27 + 0x74);
                    fn_801EC1B8(m60, m90, m90);

                    if (f25 != *(f32*)(p30 + 0x64)) {
                        fn_801EC158(m60);
                        m60[3] = f22;
                        m60[7] = f22;
                        fn_801EC1B8(m60, m90, m90);

                        fn_801EC158(m60);
                        f32 c = (f32)cos(*(f32*)(p30 + 0x64));
                        m60[5] = c;
                        m60[0] = c;
                        f32 sn = (f32)sin(*(f32*)(p30 + 0x64));
                        m60[4] = sn;
                        m60[1] = -sn;
                        fn_801EC1B8(m60, m90, m90);

                        fn_801EC158(m60);
                        m60[3] = f23;
                        m60[7] = f23;
                        fn_801EC1B8(m60, m90, m90);
                    }

                    fn_801EC158(m60);
                    m60[3] = f22;
                    m60[7] = f22;
                    fn_801EC1B8(m60, m90, m90);

                    fn_801EC158(m60);
                    m60[0] = *(f32*)(p27 + 0x4C);
                    m60[5] = *(f32*)(p27 + 0x50);
                    fn_801EC1B8(m60, m90, m90);

                    fn_801EC158(m60);
                    m60[3] = f23;
                    m60[7] = f23;
                    fn_801EC1B8(m60, m90, m90);

                    m60[0] = f29;
                    m60[1] = f25;
                    m60[2] = f25;
                    m60[3] = f27;
                    m60[4] = f25;
                    m60[5] = f28;
                    m60[6] = f25;
                    m60[7] = f26;
                    m60[8] = f25;
                    m60[9] = f25;
                    m60[10] = f24;
                    m60[11] = f25;
                    fn_801EC1B8(m60, m90, m90);

                    if (!((((s32)*arg2) >> (i + 7)) & 1)) {
                        fn_801F5304(m90, 3 * *(s32*)(p31 + 0xB0) + 0x1E, 1);
                        GXSetTexCoordGen2(
                            (GXTexCoordID)*(s32*)(p31 + 0xB0),
                            GX_TG_MTX2x4, GX_TG_TEX0,
                            (u32)(3 * *(s32*)(p31 + 0xB0) + 0x1E),
                            FALSE, GX_DUALMTX_IDENT);
                    } else {
                        fn_801EC1B8(arg3->matrix, m90, m90);
                        fn_801F5304(m90, 3 * *(s32*)(p31 + 0xB0) + 0x40, 0);
                        GXSetTexCoordGen2(
                            (GXTexCoordID)*(s32*)(p31 + 0xB0),
                            GX_TG_MTX3x4, GX_TG_POS, 0, FALSE,
                            (u32)(3 * *(s32*)(p31 + 0xB0) + 0x40));
                    }
                }
            }
        }

        p31 += 4;
        p30 += 4;
        sh4 += 4;
        sh2 += 2;
        p27 += 8;
        p26 += 0x30;
    } while (++i < 3);

    return ret;
}
