#include <types.h>
#pragma force_active on
extern "C" unsigned int __cvt_fp2unsigned(float);

struct Obj {
    u8 pad0[0xDC];
    float fDC;
    float fE0;
    float fE4;
    float fE8;
    u8 pad1[0xF4 - 0xEC];
    u32 uF4;
    u32 uF8;
    u32 uFC;
    u32 u100;
};

extern "C" void fn_801A7ABC(Obj** arg0, float f1, float f2, float f3, float f4) {
    Obj* obj = *arg0;
    if (obj != 0) {
        obj->fDC = f1;
        obj->fE0 = f2;
        obj->fE4 = f3;
        obj->fE8 = f4;
        obj = *arg0;
        if (obj != 0) {
            obj->uF4 = __cvt_fp2unsigned(f1);
            obj->uF8 = __cvt_fp2unsigned(f2);
            obj->uFC = __cvt_fp2unsigned(f3);
            obj->u100 = __cvt_fp2unsigned(f4);
        }
    }
}
