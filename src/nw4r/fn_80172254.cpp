#include <types.h>
#include <math.h>
#include <nw4r/ut/ut_algorithm.h>

#define PSVECNormalize fn_801ED008
#include <nw4r/math/math_types.h>
#pragma force_active on
#undef PSVECNormalize

typedef nw4r::math::VEC3 Vec3;
struct Ctx {
    char pad0[0x32];
    u16 count;
    char pad1[0x67 - 0x34];
    s8 f67;
    char pad2[0xE8 - 0x68];
    u16 e8;
    char pad3[0xEC - 0xEA];
    u32 seed;
    char pad4[0xF8 - 0xF0];
    s32 f8;
    char fc;
};
struct Object_vptr_1c_base { char pad[0x1c]; };
class Object_vptr_1c : public Object_vptr_1c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(u16, Vec3, Vec3, s32, void*, s32, u16, f32);
};
extern const f32 lbl_805A2EE0;
extern const f32 lbl_805A2EE4;
extern const f32 lbl_805A2EE8;
extern const f32 lbl_805A2EEC;
extern const f32 lbl_805A2EF0;
extern const f64 lbl_805A2EF8;
extern const f32 lbl_805A2F00;
extern const f32 lbl_805A2F04;
extern const f32 lbl_805A2F08;
extern const f32 lbl_805A2F0C;
extern const f32 lbl_805A2F10;
extern const f32 lbl_805A2F14;
static inline f32 randomValue(Ctx* c) {
    c->seed = c->seed * 0x343FD + 0x269EC3;
    return (f32)(c->seed >> 16) / lbl_805A2EE8;
}
extern "C" {
void fn_8016FC34(s32, Vec3*, Ctx*, Vec3*, Vec3*, Vec3*, Vec3*);
u16 fn_80170150(s32, s32, Ctx*, f32);
f64 fn_80400B3C(f32, f64);

void fn_80172254(s32 arg0, Ctx* arg1, Object_vptr_1c* arg2, s32 arg3, u32 arg4, f32* arg5, s32 arg6, s32 arg7, f32 farg0)
{
    f32 c28, v30, v29, c25, c27, v24, v31, s23, c22, s21, c20, v19, v18, v17, v16, v15, v14;
    if (arg3 >= 1) {
        v19 = arg5[0];
        v19 = ((f32)(double)nw4r::ut::Abs(v19) > lbl_805A2EE0) ? v19 : lbl_805A2EE0;
        v24 = ((f32)(double)nw4r::ut::Abs(arg5[4]) > lbl_805A2EE0)
                  ? arg5[4] : lbl_805A2EE0;
        if (arg4 & 0x02000000) {
            v18 = v19;
        } else {
            v18 = arg5[5];
            v18 = ((f32)(double)nw4r::ut::Abs(v18) > lbl_805A2EE0) ? v18 : lbl_805A2EE0;
        }
        v17 = lbl_805A2EE4;
        f32 sp70 = v17;
        if (arg4 & 0x40000) {
            v16 = arg5[2];
        } else {
            v16 = lbl_805A2EEC * (lbl_805A2EF0 * randomValue(arg1));
        }
        s32 n;
        u32 flag2 = arg4 & 0x20000;
        if (flag2 != 0) {
            f32 span = arg5[3] - arg5[2];
            f32 t = (f32)fn_80400B3C(span, lbl_805A2EF8);
            if (t < lbl_805A2F00 || t > lbl_805A2F04) {
                sp70 = (arg5[3] - arg5[2]) / (f32)arg1->count;
            } else {
                sp70 = (arg5[3] - arg5[2]) / (f32)(arg1->count - 1);
            }
        }
        n = arg3;
        if (flag2 != 0) {
            n = arg3 * arg3;
        }
        v15 = lbl_805A2EE4;
        f64 sp88 = lbl_805A2EE4;
        for (s32 i = 0; i < n; i++) {
            v14 = (lbl_805A2F08 - arg5[1]) / (lbl_805A2F08 + arg5[1]);
            if (flag2 == 0) {
                v17 = (arg5[3] - arg5[2]) * randomValue(arg1);
                v15 = lbl_805A2EEC * (lbl_805A2EF0 * randomValue(arg1));
            }
            s23 = sinf(v16 + v17);
            c22 = cosf(v16 + v17);
            s21 = sinf(v15);
            c20 = cosf(v15);
            Vec3 v54;
            v54.x = (v19 * (s23 + (s23 * (v14 * c20)))) / (lbl_805A2F0C + v14);
            v54.y = v24 * s21;
            v54.z = (v18 * ((c22 * (-v14 * c20)) - c22)) / (lbl_805A2F0C + v14);
            Vec3 w48;
            Vec3 w3c = v54;
            if (lbl_805A2EE4 != w3c.x || lbl_805A2EE4 != w3c.y || lbl_805A2EE4 != w3c.z) {
                nw4r::math::VEC3Normalize(&w3c, &w3c);
            }
            Vec3 w30(v54.x, lbl_805A2EE4, v54.z);
            if (lbl_805A2EE4 != w30.x || lbl_805A2EE4 != w30.z) {
                nw4r::math::VEC3Normalize(&w30, &w30);
            }
            Vec3 w24;
            if ((f32)sp88 == v14) {
                w24.x = s23 * (v19 * c20);
                w24.y = v24 * s21;
                w24.z = c22 * (-v18 * c20);
            } else {
                w24.x = (v19 * (s23 * (v14 * c20))) / (lbl_805A2F0C + v14);
                w24.y = v24 * s21;
                w24.z = (v18 * (c22 * (-v14 * c20))) / (lbl_805A2F0C + v14);
            }
            if (lbl_805A2EE4 != w24.x || lbl_805A2EE4 != w24.y || lbl_805A2EE4 != w24.z) {
                nw4r::math::VEC3Normalize(&w24, &w24);
            }
            fn_8016FC34(arg0, &w48, arg1, &v54, &w24, &w3c, &w30);
            arg2->slot3(fn_80170150(arg0, arg6, arg1, farg0), v54, w48,
                        arg7, &arg1->fc, arg1->f8, arg1->e8,
                        lbl_805A2F0C + ((lbl_805A2F10 * (f32)arg1->f67) * randomValue(arg1)));
            if (flag2 != 0) {
                if (((i + 1) % arg3) == 0) {
                    v15 = lbl_805A2EE4;
                    v17 += sp70;
                } else {
                    v15 += lbl_805A2F14 / (f32)arg3;
                }
            }
        }
    }
}
}