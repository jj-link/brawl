#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern "C" void fn_27_55BB8(void*, u32, s32, s32, s32, f32);
extern "C" void fn_27_55874(void*, void*, u32, s32, u32,
                            const nw4r::math::VEC3*, s32, s32, f32, f32);
extern "C" const f32 lbl_27_rodata_520;

static inline void scaleRaw(void* v, f32 s) {
    LocalScale((const Vec*)v, (Vec*)v, s);
}

struct Raw3 { u32 v[3]; };
struct Fn27Obj {
    s32 count;
    Raw3 pos;
    f32 f10;
    u32 w14;
    u32 w18;
};

extern "C" s32 fn_27_4DA80(Fn27Obj* self, void* context, void* obj,
                            s32 bit, s32 extra, f32 f) {
    if (self->count != 0) {
        f32 scale = self->f10;
        u32 flag = (self->w18 >> 5) & 1;
        if (flag == 0 && ((self->w18 >> 23) & 1) == 0) {
            scale *= f;
        }

        if (bit != 0) {
            fn_27_55BB8(obj, flag, self->count == 1, bit, extra, scale);
        } else {
            struct Scratch {
                s32 pad[2];
                Raw3 pos;
            } scratch;

            scratch.pos = self->pos;
            flag = (self->w18 >> 5) & 1;
            if (flag == 0 && ((self->w18 >> 23) & 1) == 0) {
                scaleRaw(&scratch.pos, f);
            }

            scratch.pad[0] = 1;
            fn_27_55874(context, obj, flag, self->count == 1,
                        self->w14 >> 23,
                        (const nw4r::math::VEC3*)&scratch.pos,
                        0, 0, scale, lbl_27_rodata_520);
        }

        ((u8*)obj)[0x24] = 1;
        self->count = 2;
        return 1;
    }
    return 0;
}