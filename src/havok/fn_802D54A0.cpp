#include <types.h>

#pragma force_active on

extern const unsigned char lbl_80487828[0x40];
extern f32 lbl_805A4138;
extern "C" int __cntlzw(unsigned int);

struct Ent {
    u8* base;
    s32 stride;
    u8 pad08[4];
    u8* data;
    s8 type;
    u8 pad11[3];
    s32 scale;
    u8 pad18[0x18];
};

struct Obj {
    u8 pad00[0x20];
    f32 sx, sy, sz;
    u8 pad2C[4];
    u32 shift;
    Ent* ents;
    u8 pad38[8];
    f32 fc;
};

struct Out {
    const unsigned char* vt;
    s16 pad4, flag;
    s32 pad8;
    f32 fc;
    f32 v[12];
};

inline void init(Out* out, f32 fc) {
    out->flag = 1;
    out->pad8 = 0;
    out->fc = fc;
    out->vt = lbl_80487828;
}

extern "C" void* fn_802D54A0(Obj* self, u32 index, Out* out) {
    __declspec(align(16)) f32 t[12];
    u32 idx = index & (0xFFFFFFFFU >> self->shift);
    Ent* ent = self->ents + (index >> (32 - self->shift));
    u8 *p6, *p4, *p7;

    signed char zero =
        (__cntlzw((unsigned int)((signed char)ent->type - 1)) >> 5) & 0xFF;
    if (((unsigned int)(-(signed char)zero | (signed char)zero) >> 31) != 0) {
        u8* d = ent->data + ent->scale * idx;
        u16* q = (u16*)d;
        p6 = ent->base + ent->stride * q[0];
        p4 = ent->base + ent->stride * q[1];
        p7 = ent->base + ent->stride * q[2];
    } else {
        u8* d = ent->data + ent->scale * idx;
        u32* q = (u32*)d;
        p6 = ent->base + ent->stride * q[0];
        p4 = ent->base + ent->stride * q[1];
        p7 = ent->base + ent->stride * q[2];
    }

    f32* f6 = (f32*)p6;
    f32* f4 = (f32*)p4;
    f32* f7 = (f32*)p7;
    f32 y0, z0, y1, z1, z2, y2, x0, x1, x2;

    z0 = f6[2] * self->sz;
    z1 = f4[2] * self->sz;
    z2 = f7[2] * self->sz;
    y0 = f6[1] * self->sy;
    y1 = f4[1] * self->sy;
    y2 = f7[1] * self->sy;
    x0 = f6[0] * self->sx;
    t[9] = y0;
    t[10] = z0;
    t[8] = x0;
    t[11] = lbl_805A4138;
    x1 = f4[0] * self->sx;
    x2 = f7[0] * self->sx;

    t[4] = x1;
    t[5] = y1;
    t[6] = z1;
    t[7] = lbl_805A4138;
    t[0] = x2;
    t[1] = y2;
    t[2] = z2;
    t[3] = lbl_805A4138;

    if (out != 0) {
        init(out, self->fc);
    }

    out->v[0] = t[8];
    out->v[1] = t[9];
    out->v[2] = t[10];
    out->v[3] = t[11];
    out->v[4] = t[4];
    out->v[5] = t[5];
    out->v[6] = t[6];
    out->v[7] = t[7];
    out->v[8] = t[0];
    out->v[9] = t[1];
    out->v[10] = t[2];
    out->v[11] = t[3];
    return out;
}
