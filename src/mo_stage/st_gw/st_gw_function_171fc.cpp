#pragma force_active on

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

extern const float lbl_63_rodata_23C;

static inline nw4r::math::VEC3 scaled(const nw4r::math::VEC3& in, float k) {
    nw4r::math::VEC3 out;
    LocalScale((const Vec*)&in, (Vec*)&out, k);
    return out;
}

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void fn_63_171FC(void* arg0) {
    unsigned char* s = (unsigned char*)arg0;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* m = *(unsigned char**)(*(unsigned char**)(s + 0x44) + 0);
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11c) == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                *(unsigned int*)(m + 0x11c) = (unsigned int)p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(unsigned int**)(p + 4);
                *(unsigned short*)(m + 0x122) = (unsigned short)*q;
            }
            unsigned char* pos = *(unsigned char**)(s + 0x174);
            if (pos != 0) {
                *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 8) =
                    *(nw4r::math::VEC3*)(pos + 0x18);
            }
            *(nw4r::math::VEC3*)(*(unsigned char**)(p + 4) + 0x20) =
                scaled(*(const nw4r::math::VEC3*)(s + 0x168), lbl_63_rodata_23C);
        }
    }
}