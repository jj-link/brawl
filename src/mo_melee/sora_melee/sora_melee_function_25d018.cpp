#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_25CEA4(void* self, int arg);
extern void* lbl_27_data_54140[];
}

struct fn_27_25D018_Obj {
    void* vtbl;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

extern "C" fn_27_25D018_Obj* fn_27_25D018(fn_27_25D018_Obj* self) {
    fn_27_25CEA4(self, 1);
    self->unk10 = 0;
    self->vtbl = lbl_27_data_54140;
    self->unk14 = 0;
    self->unk18 = 0;
    return self;
}
