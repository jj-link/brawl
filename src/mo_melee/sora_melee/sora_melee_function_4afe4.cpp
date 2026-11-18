#include <types.h>
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

using nw4r::math::VEC3;
struct Fn27Obj {
    u32 count;
    VEC3 vec;
    float f10;
    u32 w14;
    struct {
        u32 a : 4;
        u32 b : 1;
        u32 c : 1;
        u32 d : 26;
    } w18;
};

extern "C" const float lbl_27_rodata_4F8;
static inline void scaleVec(VEC3* v, float f) {
    LocalScale(*v, *v, f);
}
extern "C" {
void fn_27_55C84(u32 a, u32 b, u32 c, u32 d, VEC3* e, u32 f);

int fn_27_4AFE4(Fn27Obj* p, u32 a, u32 b, float f) {
    if (p->count != 0) {
        VEC3 v = p->vec;
        if (p->w18.c == 0 && p->w18.b == 0) {
            scaleVec(&v, lbl_27_rodata_4F8 / f);
        }
        fn_27_55C84(a, b, p->w18.c, p->w14 >> 23, &v, 0);
        return 1;
    }
    return 0;
}
}