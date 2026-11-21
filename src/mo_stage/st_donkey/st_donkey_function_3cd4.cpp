#include <types.h>
#include <revolution/MTX.h>
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

extern float lbl_50_rodata_98;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void fn_50_3CD4(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;

    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* m =
            **(nw4r::g3d::ScnMdlSimple***)(s + 0x44);

        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                m->m_calcWorldCallBack =
                    (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                q = *(unsigned int**)(p + 4);
                m->m_nodeIndex = (short)*q;
            }

            nw4r::math::VEC3* src =
                *(nw4r::math::VEC3**)(s + 0x164);
            if (src != 0) {
                nw4r::math::VEC3* d =
                    (nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 8);
                d->x = src->x;
                d->y = src->y;
                d->z = src->z;
            }

            const nw4r::math::VEC3& scaleSrc =
                *(nw4r::math::VEC3*)(s + 0x158);
            nw4r::math::VEC3 tmp = scaled(scaleSrc, lbl_50_rodata_98);
            *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 0x20) = tmp;
        }
    }
}