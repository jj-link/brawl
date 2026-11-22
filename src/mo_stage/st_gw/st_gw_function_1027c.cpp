#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECAdd LocalVECAdd
#define PSVECScale LocalVECScale
#define PSVECNormalize LocalVECNormalize
#define PSVECSquareMag LocalVECSquareMag
#define PSVECMag LocalVECMag
#define PSVECDotProduct LocalVECDotProduct
#define PSVECCrossProduct LocalVECCrossProduct
#include <../src/revolution/MTX/vec.c>
#undef PSVECAdd
#undef PSVECScale
#undef PSVECNormalize
#undef PSVECSquareMag
#undef PSVECMag
#undef PSVECDotProduct
#undef PSVECCrossProduct
}
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern const float lbl_63_rodata_118;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalVECScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void fn_63_1027C(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        nw4r::g3d::ScnMdlSimple* m = *(nw4r::g3d::ScnMdlSimple**)a;
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
            Vec* arr = *(Vec**)(s + 0x174);
            if (arr != 0) {
                Vec* elem = arr + *(unsigned char*)(s + 0x17d);
                *(Vec*)(*(unsigned char**)(p + 4) + 8) = *elem;
            }
            *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 0x20) =
                scaled(*(const nw4r::math::VEC3*)(s + 0x168), lbl_63_rodata_118);
        }
    }
}
