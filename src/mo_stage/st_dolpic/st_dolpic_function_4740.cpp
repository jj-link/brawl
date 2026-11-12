#include <nw4r/g3d/g3d_scnmdlsmpl.h>
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

extern const float lbl_46_rodata_D8;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void fn_46_4740(unsigned char* self) {
    unsigned char* p = self + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(self + 0x44);
        nw4r::g3d::ScnMdlSimple* m =
            *(nw4r::g3d::ScnMdlSimple**)a;
        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(self + 0xc4);
                m->m_calcWorldCallBack =
                    (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                q = *(unsigned int**)(p + 4);
                m->m_nodeIndex = (short)*q;
            }
            nw4r::math::VEC3* dst = (nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 0x20);
            *dst = scaled(*(const nw4r::math::VEC3*)(self + 0x158), lbl_46_rodata_D8);
        }
    }
}
