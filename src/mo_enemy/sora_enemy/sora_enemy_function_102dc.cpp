#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_41_rodata_BE0[];
s32 fn_41_159AC(s32 p1, s32 p2);
}

struct Outer {
    char pad[0x3C];
    soModuleAccesser* acc;
};

extern "C" void fn_41_102DC(Outer* self, s32 arg1, f32 farg0, f32 farg1, s32 arg2, s32 arg3) {
    const float* tbl = lbl_41_rodata_BE0;
    f32 mul = farg1;
    float* ptr0 = (float*)fn_41_159AC(arg1, arg2);
    float* ptr1 = (float*)fn_41_159AC(arg1, arg3);

    if (tbl[3] == farg0) {
        mul *= tbl[3];
    }
    ptr0[1] = mul;
    ptr0[7] = mul;

    if (tbl[2] == farg0) {
        ptr1[3] = soValueAccesser::getValueFloat(self->acc, 0xBCA, 0);
        ptr1[5] = tbl[0];
        ptr1[7] = soValueAccesser::getValueFloat(self->acc, 0xBC9, 0);
    } else {
        ptr1[3] = tbl[3] * soValueAccesser::getValueFloat(self->acc, 0xBCA, 0);
        ptr1[5] = tbl[3] * soValueAccesser::getValueFloat(self->acc, 0xBC9, 0);
        ptr1[7] = tbl[0];
    }
}