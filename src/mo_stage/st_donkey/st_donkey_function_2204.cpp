#include <types.h>
#include <revolution/MTX.h>
#include <mt/mt_vector.h>
#define PSVECAdd l_VECAdd
#define PSVECScale l_VECScale
#define PSVECNormalize l_VECNormalize
#define PSVECMag l_VECMag
#define PSVECDotProduct l_VECDotProduct
#define PSVECCrossProduct l_VECCrossProduct
#define C_VECHalfAngle l_VECHalfAngle
#define PSVECSquareDistance l_VECSquareDistance
namespace {
#include <../src/revolution/MTX/vec.c>
}
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);
extern float lbl_50_rodata_60;

static inline Vec3f scaleVec(const Vec3f& v, float s) {
    Vec3f out;
    PSVECScale((const Vec*)&v, (Vec*)&out, s);
    return out;
}

extern "C" void fn_50_2204(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* a = *(u8**)(self + 0x44);
        u8* m = *(u8**)a;
        if (m != 0) {
            if (*(u32*)(m + 0x11c) == 0) {
                *(u32*)(p + 0xc) = 0;
                u32* q = *(u32**)(p + 4);
                *q = *(u32*)(self + 0xc4);
                *(u8**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(u32**)(p + 4);
                *(u16*)(m + 0x122) = (u16)*q;
            }
            Vec3f* d = (Vec3f*)(*(u8**)(p + 4) + 0x20);
            *d = scaleVec(*(Vec3f*)(self + 0x158), lbl_50_rodata_60);
        }
    }
}
