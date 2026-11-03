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

extern const float lbl_27_rodata_44;
extern const float lbl_27_rodata_48;

struct Arg0 {
    nw4r::math::VEC3 pos;
    f32 scale;
    f32 pad1[9];
    nw4r::math::VEC3 half;
    f32 pad2[12];
    const nw4r::math::VEC3 vec;
};

struct Tmp {
    nw4r::math::_VEC3 maxV;
    nw4r::math::_VEC3 minV;
    nw4r::math::VEC3 off;
};

extern "C" void fn_27_2898(Arg0* p, f32* out)
{
    if (((unsigned char*)p)[0x25] == 1) {
        out[2] = lbl_27_rodata_44;
        out[1] = lbl_27_rodata_44;
        out[0] = lbl_27_rodata_44;
        out[5] = lbl_27_rodata_48;
        out[4] = lbl_27_rodata_48;
        out[3] = lbl_27_rodata_48;
        return;
    }

    Tmp t;
    LocalScale((const Vec*)&p->vec, (Vec*)&t.off, p->scale);

    if (p->pos.x > p->half.x) {
        t.maxV.x = p->pos.x + t.off.x;
        t.minV.x = p->half.x - t.off.x;
    } else {
        t.maxV.x = p->half.x + t.off.x;
        t.minV.x = p->pos.x - t.off.x;
    }

    if (p->pos.y > p->half.y) {
        t.maxV.y = p->pos.y + t.off.y;
        t.minV.y = p->half.y - t.off.y;
    } else {
        t.maxV.y = p->half.y + t.off.y;
        t.minV.y = p->pos.y - t.off.y;
    }

    if (p->pos.z > p->half.z) {
        t.maxV.z = p->pos.z + t.off.z;
        t.minV.z = p->half.z - t.off.z;
    } else {
        t.maxV.z = p->half.z + t.off.z;
        t.minV.z = p->pos.z - t.off.z;
    }

    if (t.minV.x < out[0]) out[0] = t.minV.x;
    if (t.minV.x > out[3]) out[3] = t.minV.x;
    if (t.minV.y < out[1]) out[1] = t.minV.y;
    if (t.minV.y > out[4]) out[4] = t.minV.y;
    if (t.minV.z < out[2]) out[2] = t.minV.z;
    if (t.minV.z > out[5]) out[5] = t.minV.z;

    if (t.maxV.x < out[0]) out[0] = t.maxV.x;
    if (t.maxV.x > out[3]) out[3] = t.maxV.x;
    if (t.maxV.y < out[1]) out[1] = t.maxV.y;
    if (t.maxV.y > out[4]) out[4] = t.maxV.y;
    if (t.maxV.z < out[2]) out[2] = t.maxV.z;
    if (t.maxV.z > out[5]) out[5] = t.maxV.z;
}
