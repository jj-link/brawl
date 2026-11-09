#include <nw4r/math.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

struct ColorWork {
    char pad0[0x6c];
    u8 mode;
    u8 scaleR;
    u8 scaleG;
    u8 scaleB;
    u8 scaleA;
    u8 baseR;
    u8 baseG;
    u8 baseB;
    u8 baseA;
    char pad75[0x3];
    f32 threshold;
    nw4r::math::VEC3 pos;
    nw4r::math::VEC3 prevPos;
};

struct RGBA8 {
    u8 r, g, b, a;
};

extern "C" void fn_801ECD70(void* matrix, s32 offset, void* out);
extern "C" f32 fn_801ED04C(void* vec);
extern char lbl_804A3E40[];
extern f32 lbl_805A2D58;
extern f32 lbl_805A2D5C;

static inline u8 scaleChannel(u8 c, u8 s) {
    return (u8)((s32)((c * s) + 0x80) >> 8);
}

extern "C" void fn_8016E0C4(ColorWork* self, s32 arg1, RGBA8* a, RGBA8* b, int arg) {
    nw4r::math::VEC3 tmp;

    switch (self->mode) {
    case 1:
        a->r = scaleChannel(a->r, self->scaleR);
        a->g = scaleChannel(a->g, self->scaleG);
        a->b = scaleChannel(a->b, self->scaleB);
        a->a = scaleChannel(a->a, self->scaleA);
        b->r = scaleChannel(b->r, self->scaleR);
        b->g = scaleChannel(b->g, self->scaleG);
        b->b = scaleChannel(b->b, self->scaleB);
        b->a = scaleChannel(b->a, self->scaleA);
        return;
    case 2:
        if (self->threshold < lbl_805A2D58) {
            a->r = scaleChannel(a->r, self->scaleR);
            a->g = scaleChannel(a->g, self->scaleG);
            a->b = scaleChannel(a->b, self->scaleB);
            a->a = scaleChannel(a->a, self->scaleA);
            b->r = scaleChannel(b->r, self->scaleR);
            b->g = scaleChannel(b->g, self->scaleG);
            b->b = scaleChannel(b->b, self->scaleB);
            b->a = scaleChannel(b->a, self->scaleA);
            return;
        }
        fn_801ECD70(lbl_804A3E40, arg1 + 0xAC, &tmp);
        nw4r::math::VEC3Sub(&tmp, &tmp, &self->pos);
        f32 len = fn_801ED04C(&tmp);
        if (len > self->threshold) {
            a->r = scaleChannel(a->r, self->scaleR);
            a->g = scaleChannel(a->g, self->scaleG);
            a->b = scaleChannel(a->b, self->scaleB);
            a->a = scaleChannel(a->a, self->scaleA);
            b->r = scaleChannel(b->r, self->scaleR);
            b->g = scaleChannel(b->g, self->scaleG);
            b->b = scaleChannel(b->b, self->scaleB);
            b->a = scaleChannel(b->a, self->scaleA);
            return;
        }
        {
            f32 t = (lbl_805A2D5C * len) / self->threshold;
            s32 w = (s32)t;
            u16 r = (self->baseR << 8) + (w * (self->scaleR - self->baseR));
            u16 g = (self->baseG << 8) + (w * (self->scaleG - self->baseG));
            u16 bb = (self->baseB << 8) + (w * (self->scaleB - self->baseB));
            u16 aa = (self->baseA << 8) + (w * (self->scaleA - self->baseA));
            a->r = (u8)((s32)((a->r * r) + 0x80) >> 0x10);
            a->g = (u8)((s32)((a->g * g) + 0x80) >> 0x10);
            a->b = (u8)((s32)((a->b * bb) + 0x80) >> 0x10);
            a->a = (u8)((s32)((a->a * aa) + 0x80) >> 0x10);
            b->r = (u8)((s32)((b->r * r) + 0x80) >> 0x10);
            b->g = (u8)((s32)((b->g * g) + 0x80) >> 0x10);
            b->b = (u8)((s32)((b->b * bb) + 0x80) >> 0x10);
            b->a = (u8)((s32)((b->a * aa) + 0x80) >> 0x10);
        }
        return;
    }
}
