#include <types.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_D8;
extern "C" const float lbl_113_rodata_DC;
extern "C" const double lbl_113_rodata_E0;

struct S {
    void* p;
    u8 b;
};

extern "C" float fn_113_23524(S* self) {
    if (self->b == 1) {
        return lbl_113_rodata_D8;
    }
    return (float)*(s32*)((char*)self->p + 4) / lbl_113_rodata_DC;
}
