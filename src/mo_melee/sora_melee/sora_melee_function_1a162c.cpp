#include <types.h>
#pragma force_active on

struct fn_27_1A162C_obj {
    u32 unk0;
    u32 unk4;
    u32 top : 2;
    u32 rest : 30;
};

extern "C" {
void fn_27_1A162C(fn_27_1A162C_obj* obj, u32 val) {
    obj->top = val;
}
}
