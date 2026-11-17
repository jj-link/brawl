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

struct Output {
    char pad[0x24];
    u8 valid;
};

class Container {
public:
    virtual void v0();
    virtual u32* get(s32);
    virtual void v4();
    virtual s32 getState();
    virtual void v6();
};

struct Raw3 {
    u32 d[3];
};

struct Obj {
    s32 state;                      // 0x00
    char pad4[0x4];                 // 0x04
    Raw3 pos;                       // 0x08
    f32 scale;                      // 0x14
    char pad18[0x1C];               // 0x18
    u32 flags34;                    // 0x34
    u32 flags38;                    // 0x38
    char pad3c[0x4];                // 0x3C
    u32 flag40;                     // 0x40
    Container c;                    // 0x44
};

struct Scratch {
    s32 flag;                       // 0x00
    s32 pad;                        // 0x04
    Raw3 v;                         // 0x08
};

extern "C" void fn_27_55874(void*, Output*, u32, s32, u32,
                            const Raw3*, const Raw3*, s32, f32, f32);
extern "C" void fn_27_55BB8(Output*, u32, s32, s32, s32, f32);
extern "C" float lbl_27_rodata_490;

static inline void scaleRaw(Raw3* v, f32 s) {
    LocalScale((const Vec*)v, (Vec*)v, s);
}

extern "C" s32 fn_27_389E0(Obj* self, void* ctx, Output* out, s32 bit, u32 mode,
                           s32 a5, s32 a6, f32 scale) {
    if (self->state != 0) {
        f32 v = self->scale;
        if ((self->flag40 >> 31) == 0 && ((self->flags38 >> 22) & 1) == 0) {
            v *= scale;
        }

        if (a5 != 0) {
            fn_27_55BB8(out, self->flag40 >> 31, (self->state - 1) == 0, a5, a6, v);
        } else {
            Scratch s;
            s.v = self->pos;
            if (((self->flags38 >> 22) & 1) == 0) {
                scaleRaw(&s.v, scale);
            }
            s.flag = 1;
            fn_27_55874(ctx, out, self->flag40 >> 31, (self->state - 1) == 0,
                        self->flags34 >> 23, &s.v, 0, 0, v, lbl_27_rodata_490);
        }

        u32* p = self->c.get(2);
        *p = 1u << bit;
        if (self->c.getState() == 7) {
            u32* q = self->c.get(2);
            u32* d = self->c.get(6);
            *d = *q;
        }

        if ((self->flags38 >> 20) & 1) {
            if (mode == 1) {
                u32* r = self->c.get(0);
                r[1] &= ~8u;
            } else {
                u32* r = self->c.get(0);
                r[1] |= 8u;
            }
        }

        out->valid = 1;
        self->state = 2;
        return 1;
    }
    return 0;
}
