#include <types.h>
#include <nw4r/math/math_types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <mt/mt_prng.h>
#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_3698;
extern const float lbl_27_rodata_36AC;
}
using nw4r::math::VEC3;
inline VEC3* addv(register VEC3* pOut, register const VEC3* pA, register const VEC3* pB) {
    register f32 w3, w2, w1, w0;
    asm {
        psq_l  w3, 0(pB), 0, 0
        psq_l  w2, 8(pA), 1, 0
        psq_l  w1, 8(pB), 1, 0
        psq_l  w0, 0(pA), 0, 0
        ps_add w1, w2, w1
        ps_add w0, w0, w3
        psq_st w1, 8(pOut), 1, 0
        psq_st w0, 0(pOut), 0, 0
    }
    return pOut;
}
extern "C" void fn_27_226E2C(void* arg0, nw4r::math::VEC3* out) {
    u8* self = (u8*)arg0;
    u8 count = self[0x54];
    int selected = (int)((float)count * randf());
    nw4r::math::VEC3 first, second;
    first.x = first.y = first.z = lbl_27_rodata_3698;
    second.x = second.y = second.z = lbl_27_rodata_3698;
    if ((u8)selected < self[0x54] && self[4] == 1) {
        nw4r::math::MTX34 b, a;
        (*(nw4r::g3d::ScnMdlSimple**)(self + 12))->GetScnMtxPos(&a, (nw4r::g3d::ScnObj::ScnObjMtxType)1, (*(u16**)(self + 80))[(u8)selected * 2]);
        first.z = a._23;
        first.y = a._13;
        first.x = a._03;
        addv(&first, &first, (nw4r::math::VEC3*)(self + 20));
        (*(nw4r::g3d::ScnMdlSimple**)(self + 12))->GetScnMtxPos(&b, (nw4r::g3d::ScnObj::ScnObjMtxType)1, (*(u16**)(self + 80))[(u8)selected * 2 + 1]);
        second.z = b._23;
        second.y = b._13;
        second.x = b._03;
        addv(&second, &second, (nw4r::math::VEC3*)(self + 20));
    }
    float t = randf();
    float s = lbl_27_rodata_36AC - t;
    register f32 sr = s;
    register f32 tr = t;
    register nw4r::math::VEC3* pa = &first;
    register nw4r::math::VEC3* pb = &second;
    register nw4r::math::VEC3* po = out;
    register f32 p0, p1, p2, p3;
    asm {
        psq_l p0, 0(pa), 0, 0
        psq_l p1, 8(pa), 1, 0
        psq_l p2, 0(pb), 0, 0
        psq_l p3, 8(pb), 1, 0
        ps_muls0 p0, p0, sr
        ps_muls0 p1, p1, sr
        ps_madds0 sr, p2, tr, p0
        ps_madds0 tr, p3, tr, p1
        psq_st sr, 0(po), 0, 0
        psq_st tr, 8(po), 1, 0
    }
}
