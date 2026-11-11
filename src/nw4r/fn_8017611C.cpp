#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active on

using namespace nw4r::math;

extern "C" float fn_801622A0(float);
extern "C" void fn_80166B8C(void*, MTX34*);
extern "C" void fn_8016DE48(void*, MTX34*);
extern "C" void fn_801EC41C(MTX34*, MTX34*);
extern "C" void fn_80162B40(void*, const void*, void*);
extern "C" void fn_801ECD70(void*, f32*, f32*, f32, f32, f32);

extern const float lbl_805A2F60;
extern const float lbl_805A2F64;
extern const float lbl_805A2F88;

struct Work {
    void* unk0;
    s32 unk4;
    MTX34 unk8;
    MTX34 unk38;
    MTX34 unk68;
    VEC3 unk98;
    VEC3 unkA4;
    VEC3 unkB0;
};

static inline float magnitude(float s) {
    if (s <= lbl_805A2F64)
        return lbl_805A2F64;
    return s * fn_801622A0(s);
}

static inline VEC3& divBy(VEC3& v, f32 x) {
    VEC3Scale(&v, &v, lbl_805A2F60 / x);
    return v;
}

static inline bool normalizeVec(VEC3* v) {
    float s = VEC3Dot(v, v);
    if (s < lbl_805A2F88)
        return false;
    divBy(*v, magnitude(s));
    return true;
}

extern "C" Work* fn_8017611C(Work* self, s32 arg1, void* arg2) {
    self->unk4 = arg1;
    self->unk0 = arg2;

    fn_80166B8C(*(void**)((char*)arg2 + 0x20), &self->unk8);
    fn_8016DE48(arg2, &self->unk38);
    fn_801EC41C(&self->unk38, &self->unk68);

    VEC3 v(*(f32*)((char*)self + 0xC),
           *(f32*)((char*)self + 0x1C),
           *(f32*)((char*)self + 0x2C));
    fn_80162B40(&v, &self->unk68, &v);
    if (!normalizeVec(&v))
        v = VEC3(lbl_805A2F64, lbl_805A2F60, lbl_805A2F64);
    self->unk98 = v;

    VEC3 p(*(f32*)((char*)self + 0x14),
           *(f32*)((char*)self + 0x24),
           *(f32*)((char*)self + 0x34));
    fn_801ECD70(&self->unk68, (f32*)&p, (f32*)&p, p.x, p.y, p.z);
    self->unkA4.x = p.x;
    self->unkA4.y = p.y;
    self->unkA4.z = p.z;

    void* ent = *(void**)((char*)arg2 + 0x24);
    switch ((s32)*(u8*)((char*)ent + 0x13E)) {
    case 5: {
        VEC3 w;
        w.z = *(f32*)((char*)self + 0x8C);
        w.y = *(f32*)((char*)self + 0x7C);
        w.x = *(f32*)((char*)self + 0x6C);
        if (!normalizeVec(&w))
            w = VEC3(lbl_805A2F64, lbl_805A2F60, lbl_805A2F64);
        self->unkB0 = w;
        break;
    }
    default:
        break;
    }

    return self;
}
