#include <types.h>
#include <ai/ai_mgr.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct Rect {
    char pad00[0x18];
    f32 x18;
    f32 x1c;
    f32 x20;
    f32 x24;
    f32 x28;
    f32 x2c;
    f32 x30;
    f32 x34;
    f32 x38;
    f32 x3c;
    u32 flags;
};

extern "C" {
int fn_27_1ED404(void*, const Vec2f*, const Vec2f*, int, int, void*);
int fn_27_1F11F8(void*, void*, void*, float, float);

inline int trace(void* ctx, const Vec2f& a, const Vec2f& b,
                 void* ignore) {
    return fn_27_1ED404(ctx, &a, &b, 0xff, 0, ignore) != 0;
}

#define fn_27_1ED404(ctx, a, b, mask, flags, ignore) trace(ctx, a, b, ignore)

s8 fn_27_1F0278(void* ctx, Rect* A, Rect* B, s8 c,
                float scale, float margin) {
    f32 k0 = -99999.9f;
    f32 k1 = 99999.9f;
    f32 k2 = 0.0f;
    f32 k3 = -40.0f;
    f32 k4 = 5.0f;
    f64 d6 = 4503601774854144.0;
    f32 k8 = 50.0f;
    f32 k9 = 0.01f;
    f32 k10 = 12.0f;
    f32 k11 = 45.0f;
    f32 k12 = 55.0f;
    f32 k13 = 30.0f;
    f32 k14 = 10.0f;
    f32 k15 = 2.0f;
    f32 k16 = 80.0f;
    f32 k17 = -100.0f;
    f32 k18 = 38.0f;
    f32 k19 = 40.0f;
    f32 k20 = 0.0001f;
    f32 k21 = 1.0f;
    f32 k22 = 20.0f;
    f32 k23 = 28.5f;
    f32 k24 = 8.5f;
    f32 k25 = 11.0f;
    f32 k26 = -0.1f;
    f32 k27 = 0.1f;
    f32 k28 = 0.000000000000000000000000000000000000011754944f;
    f32 k29 = 75.0f;
    f32 k30 = 120.0f;
    f32 k31 = 60.0f;
    f32 k32 = 15.0f;
    f32 k33 = 0.5f;
    f32 k34 = -55.0f;
    f32 k35 = -14.0f;
    f32 k36 = 14.0f;
    f32 k37 = -70.0f;
    f32 k38 = 70.0f;
    f32 k39 = -50.0f;
    f32 k40 = 22.0f;
    f32 k41 = 35.0f;
    f32 k42 = -39.0f;
    f32 k43 = 39.0f;
    f32 k44 = -54.0f;
    f32 k45 = 54.0f;
    f32 k46 = -1.0f;
    f32 k47 = 200.0f;
    f32 k48 = 400.0f;
    f32 k49 = 150.0f;
    f32 k50 = 160.0f;
    f32 k51 = 1.5f;
    f32 k52 = -88.0f;
    f32 k53 = -90.0f;
    f32 k54 = 44.0f;
    f32 k55 = 46.0f;
    f32 k56 = 10000.0f;
    f32 k57 = -74.0f;
    f32 k58 = -76.0f;
    f32 k59 = 85.0f;
    f32 k60 = -85.0f;
    f32 k61 = 0.0000001f;
    f32 k62 = 0.3f;
    f32 k63 = -0.3f;
    f32 k64 = 9999980000.0f;
    f32 k65 = 0.00001f;
    f32 k66 = -999999.9f;
    f32 k67 = 1.2f;
    f32 k68 = -0.5f;
    f32 k69 = 100.0f;
    f32 k70 = 2.5f;
    f32 k71 = 225.0f;
    f32 k72 = 25.0f;
    f32 k73 = 36.0f;
    f32 k74 = -0.8f;
    f32 k75 = 1000000.0f;
    f32 k76 = -10000000.0f;
    f32 k77 = 0.8f;
    f32 k78 = -30.0f;
    f32 k79 = -300.0f;
    f32 k80 = -600.0f;
    f32 k81 = -400.0f;
    f32 k82 = 10000000.0f;
    f32 k83 = 100000.0f;
    f32 k84 = 1000.0f;
    f32 k85 = 0.2f;
    f32 k86 = 3.0f;
    f32 k87 = 6.0f;
    f32 k88 = -10.0f;
    f32 k89 = -5.0f;
    u32 fB;
    u32 fA;
    u32 bF1;
    u32 aF1;
    bool bF2;
    bool aF2;
    int r28 = 0;
    float v[8];
    float f28 = scale;
    float f31, level, f29, f30;
    float otherMargin;
    float dx0, dy0, thr, d, xv;

#define b0x v[6]
#define b0y v[7]
#define b1x v[4]
#define b1y v[5]
#define a0x v[2]
#define a0y v[3]
#define a1x v[0]
#define a1y v[1]
#define FC ((float)c)
#define ABSF(x) nw4r::ut::Abs(x)
#define AI_STATE(p) (*(int*)((char*)(p) + 0x370))

    if (c > 0) {
        fB = B->flags;
        b0x = B->x20;
        fA = A->flags;
        bF1 = (fB >> 9) & 1;
        aF1 = (fA >> 8) & 1;
        bF2 = (fB >> 8) & 1;
        aF2 = (fA >> 9) & 1;
        b0y = B->x24;
        b1x = B->x18;
        b1y = B->x1c;
        a0x = A->x18;
        a0y = A->x1c;
        a1x = A->x20;
        a1y = A->x24;
        level = A->x30;
        f31 = margin + ((fB & 0x80) ? 14.0f : (-1.0f));
        otherMargin = margin + ((fB & 0x40) ? 14.0f : (-1.0f));
    } else {
        fB = B->flags;
        b0x = B->x18;
        fA = A->flags;
        bF1 = (fB >> 8) & 1;
        aF1 = (fA >> 9) & 1;
        bF2 = (fB >> 9) & 1;
        aF2 = (fA >> 8) & 1;
        b0y = B->x1c;
        b1x = B->x20;
        b1y = B->x24;
        a0x = A->x20;
        a0y = A->x24;
        a1x = A->x18;
        a1y = A->x1c;
        level = A->x34;
        f31 = margin + ((fB & 0x40) ? 14.0f : (-1.0f));
        otherMargin = margin + ((fB & 0x80) ? 14.0f : (-1.0f));
    }

    if (aF1 != 0 &&
        ABSF(b0x - a0x) < 0.01f &&
        ABSF(b0y - a0y) < 0.01f) {
        r28 = c * 9;
        goto end;
    }

    if (aF2 != 0 &&
        ABSF(b1x - a1x) < 0.01f &&
        ABSF(b1y - a1y) < 0.01f)
        goto end;

    if (!(FC * (b0x - a0x) <= 0.0f))
        goto neg_path;

    if (!(ABSF(b0x - a0x) <
          scale * (2.0f + (a0y - b0y) / margin)))
        goto b58;

    f29 = a0x + FC;
    if (aF1 == 0 && AI_STATE(g_aiMgr) == 0x35 &&
        (level - a0y) < f31 && (b0y - a0y) < f31) {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(f29, 3.0f + level), 0xff, 0, 0) == 0) {
            if (fn_27_1ED404(
                    ctx, Vec2f(f29, 3.0f + level),
                    Vec2f(b0x - FC, 3.0f + level),
                    0xff, 0, 0) == 0) {
                if (fn_27_1ED404(
                        ctx, Vec2f(b0x - FC, 3.0f + level),
                        Vec2f(b0x - FC, 3.0f + b0y),
                        0xff, 0, 0) == 0) {
                    r28 = c * 14;
                    goto end;
                }
            }
        }
    }

    if (!(b0y > a0y))
        goto l90c;

    f30 = b0x - FC;
    if (FC * (f30 - f29) > 0.0f)
        f29 = f30;
    if (!(b0y - a0y < f31))
        goto end;
    if (bF1 == 0)
        goto end;

    {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(f30, 3.0f + b0y), 0xff, 0, 0) == 0) {
            r28 = c;
            goto end;
        }
    }

    if (AI_STATE(g_aiMgr) == 5) {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + b0y),
                Vec2f(f30, 3.0f + b0y), 0xff, 0, 0) == 0)
            r28 = c * 7;
        goto end;
    }

    {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(f29, 3.0f + b0y), 0xff, 0, 0) == 0) {
            if (fn_27_1ED404(
                    ctx, Vec2f(f29, 3.0f + b0y),
                    Vec2f(f30, 3.0f + b0y), 0xff, 0, 0) == 0) {
                r28 = c * 7;
                goto end;
            }
        }
    }

    if (AI_STATE(ctx) == 8 || AI_STATE(ctx) == 0x2c)
        goto end;

    {
        f29 -= 6.0f * FC;
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(f29, 3.0f + b0y), 0xff, 0, 0) != 0)
            goto end;

        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + b0y),
                Vec2f(f30, 3.0f + b0y), 0xff, 0, 0) == 0)
            r28 = c * 10;
        thr = FC;
        goto end;
    }

l90c:
    if (((A->flags & 0x20000) | (A->flags & 0x20)) != 0 &&
        FC * (b0x - a0x) > (-10.0f)) {
        r28 = c * 13;
        goto end;
    }

    if (aF1 == 0)
        goto end;

    dy0 = b0x - FC;
    {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(dy0, 3.0f + b0y), 0xff, 0, A) == 0) {
            r28 = c * 2;
            goto end;
        }
    }

    if (!(ABSF(b0x - a0x) < 2.0f * f28))
        goto end;

    {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(dy0, 3.0f + a0y), 0xff, 0, 0) == 0) {
            if (fn_27_1ED404(
                    ctx, Vec2f(dy0, 3.0f + a0y),
                    Vec2f(dy0, 3.0f + b0y), 0xff, 0, 0) == 0) {
                r28 = c * 8;
                goto end;
            }
        }
    }

    f28 = 0.5f * (b0x + b1x);
    {
        if (fn_27_1ED404(
                ctx, Vec2f(f29, 3.0f + a0y),
                Vec2f(f28, 3.0f + a0y), 0xff, 0, 0) != 0)
            goto end;

        if (fn_27_1ED404(
                ctx, Vec2f(f28, 3.0f + a0y),
                Vec2f(f28, 3.0f + b0y), 0xff, 0, 0) != 0)
            goto end;

        r28 = c * 11;
        thr = FC;
        goto end;
    }

b58:
    if (fn_27_1F11F8(ctx, A, B, scale, margin) != 0)
        r28 = c * 15;
    thr = FC;
    goto end;

neg_path:
    if (FC * (a1x - b1x) <= 0.0f)
        goto end;

    d = b1x - b0x;
    if (ABSF(d) > 0.1f) {
        f31 = b0y + ((b1y - b0y) / d) * (a0x - b0x);
    } else
        f31 = 10.0f + a0y;

    if (a0y > f31) {
        if (((fA & 0x20000) | (fA & 0x20)) != 0) {
            if (fn_27_1ED404(
                    ctx, Vec2f(a0x + FC, a0y - 1.0f),
                    Vec2f(a0x + FC, 3.0f + f31), 0xff, 0, B) == 0) {
                r28 = c * -3;
                goto end;
            }
        }

        if (aF1 == 0)
            goto end;
        if (!(a0x - FC > B->x18 - 30.0f))
            goto end;
        if (!(a0x - FC < 30.0f + B->x20))
            goto end;

        if (fn_27_1ED404(
                    ctx, Vec2f(a0x - 2.0f * FC, 3.0f + a0y),
                    Vec2f(b1x + 2.0f * FC, 3.0f + b1y),
                    0xff, 0, B) != 0) {
            if (fn_27_1ED404(
                    ctx, Vec2f(a0x - 6.0f * FC, 3.0f + a0y),
                    Vec2f(a0x - 6.0f * FC, 3.0f + f31),
                    0xff, 0, B) != 0)
                goto end;

            if (fn_27_1ED404(
                    ctx, Vec2f(a0x - 6.0f * FC, 3.0f + f31),
                    Vec2f(b1x + 2.0f * FC, 3.0f + b1y),
                    0xff, 0, B) != 0)
                goto end;
        }

        r28 = c * -12;
        goto end;
    }

    if (!(b1y - a0y < otherMargin))
        goto l1194;

    if (bF2 == 0)
        goto f58;

    if (!(FC * (b1x - a0x) >= (-5.0f)))
        goto f58;

    {
        if (fn_27_1ED404(
                ctx, Vec2f(b1x - FC, 3.0f + a0y),
                Vec2f(b1x - FC, 3.0f + b1y), 0xff, 0, 0) == 0)
            r28 = c * -4;
        goto end;
    }

f58:
    if (!(FC * (b0x - a1x) < 0.0f))
        goto end;

    {
        if (fn_27_1ED404(
                ctx, Vec2f(a0x + FC, 3.0f + a0y),
                Vec2f(a0x + FC, 3.0f + b1y), 0xff, 0, 0) == 0) {
            r28 = c * -5;
            goto end;
        }
    }

    {
        float t = 0.5f * (a0x + a1x);
        xv = t - FC;
        if (!(FC * (xv - b0x) < 0.0f))
            goto l10bc;

        if (fn_27_1ED404(
                ctx, Vec2f(xv, 3.0f + a0y),
                Vec2f(xv, 3.0f + b1y), 0xff, 0, 0) == 0) {
            r28 = c * -6;
            goto end;
        }
    }

l10bc:
    if (AI_STATE(ctx) != 0x2c)
        goto end;
    if (bF1 == 0)
        goto end;

    {
        if (fn_27_1ED404(
                ctx, Vec2f(xv, 3.0f + a0y),
                Vec2f(xv, 3.0f + b0y), 0xff, 0, 0) != 0)
            goto end;
    }

    {
        if (fn_27_1ED404(
                ctx, Vec2f(xv, 3.0f + b0y),
                Vec2f(b0x - FC, 3.0f + b0y), 0xff, 0, 0) == 0)
            r28 = c * 18;
    }
    goto end;

l1194:
    if (fn_27_1F11F8(ctx, A, B, scale, margin) != 0)
        r28 = c * -16;
    goto end;

end:
    return r28;

#undef b0x
#undef b0y
#undef b1x
#undef b1y
#undef a0x
#undef a0y
#undef a1x
#undef a1y
#undef FC
#undef ABSF
#undef AI_STATE
}
}
