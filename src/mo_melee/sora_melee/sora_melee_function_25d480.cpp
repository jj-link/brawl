#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_25CEA4(void* self, int arg);
extern void* lbl_27_data_54340[];
extern u32 lbl_27_data_54290;
}

struct Object {
    void* vtbl;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

extern "C" Object* fn_27_25D480(Object* self, u32 arg) {
    fn_27_25CEA4(self, 1);
    self->unk10 = arg;
    self->vtbl = lbl_27_data_54340;
    self->unk14 = lbl_27_data_54290;
    self->unk18 = 0;
    self->unk14 = lbl_27_data_54290;
    self->unk18 = 0;
    self->unk8 = 0;
    return self;
}
