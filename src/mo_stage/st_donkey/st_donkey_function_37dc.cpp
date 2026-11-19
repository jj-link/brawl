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

extern "C" {
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern float lbl_50_rodata_84;
}

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void fn_50_37DC(unsigned char* self) {
    unsigned char* p = self + 0xD0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(self + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(unsigned*)(m + 0x11c) == 0) {
                *(unsigned*)(p + 0xc) = 0;
                unsigned* q = *(unsigned**)(p + 4);
                *q = *(unsigned*)(self + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(unsigned**)(p + 4);
                *(unsigned short*)(m + 0x122) = (unsigned short)*q;
            }
            if (*(unsigned*)(self + 0x164) != 0) {
                float* d = *(float**)(p + 4);
                d[2] = *(float*)(self + 0x16c);
                d[3] = *(float*)(self + 0x170);
                d[4] = *(float*)(self + 0x174);
            }
            nw4r::math::VEC3 v = scaled(*(nw4r::math::VEC3*)(self + 0x158), lbl_50_rodata_84);
            float* d = *(float**)(p + 4);
            d[8] = v.x;
            d[9] = v.y;
            d[10] = v.z;
        }
    }
}