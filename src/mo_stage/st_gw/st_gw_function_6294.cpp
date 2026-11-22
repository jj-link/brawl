#include <types.h>
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

extern const float lbl_63_rodata_A0;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void fn_63_6294(void* arg0) {
    unsigned char* s = (unsigned char*)arg0;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* m =
            **(nw4r::g3d::ScnMdlSimple***)(s + 0x44);
        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                m->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                q = *(unsigned int**)(p + 4);
                m->m_nodeIndex = (short)*q;
            }
            nw4r::math::VEC3* src = *(nw4r::math::VEC3**)(s + 0x174);
            if (src != 0) {
                *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 8) = *src;
            }
            *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 0x20) =
                scaled(*(const nw4r::math::VEC3*)(s + 0x168), lbl_63_rodata_A0);
        }
    }
}