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

extern const float lbl_63_rodata_14C;

extern "C" void fn_63_11484(unsigned char* self) {
    unsigned char* p = self + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(self + 0x44);
        nw4r::g3d::ScnMdlSimple* m = *(nw4r::g3d::ScnMdlSimple**)a;
        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(self + 0xc4);
                m->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                q = *(unsigned int**)(p + 4);
                m->m_nodeIndex = (short)*q;
            }
            float* d = *(float**)(p + 4);
            d[2] = *(float*)(self + 0x180);
            d[3] = *(float*)(self + 0x184);
            d[4] = *(float*)(self + 0x188);
            nw4r::math::VEC3 v;
            LocalScale((const Vec*)(self + 0x168), (Vec*)&v, lbl_63_rodata_14C);
            d = *(float**)(p + 4);
            d[8] = v.x;
            d[9] = v.y;
            d[10] = v.z;
        }
    }
}