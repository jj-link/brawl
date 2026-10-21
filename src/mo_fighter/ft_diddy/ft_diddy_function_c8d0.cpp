#include <types.h>
#pragma force_active on

extern "C" const float lbl_115_rodata_C;
extern "C" const float lbl_115_rodata_28;
extern "C" float* fn_115_C8BC(float* dst, const float* src);

struct FtDiddyObj {
    u8 pad0[0x8];
    float f8[2];
    float f10[2];
    float f18[2];
    float f20[2];
    float f28[2];
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_115_C8D0(FtDiddyObj* obj) {
    float tmp[2];
    float tmp2[2];
    tmp[0] = lbl_115_rodata_C;
    tmp[1] = lbl_115_rodata_C;
    float* p = fn_115_C8BC(obj->f20, tmp);
    p = fn_115_C8BC(obj->f10, p);
    fn_115_C8BC(obj->f8, p);
    tmp2[0] = lbl_115_rodata_28;
    tmp2[1] = lbl_115_rodata_28;
    float* q = fn_115_C8BC(obj->f28, tmp2);
    fn_115_C8BC(obj->f18, q);
    obj->flag31 = 0;
    obj->flag30 = 0;
    obj->flag32 = 1;
}
