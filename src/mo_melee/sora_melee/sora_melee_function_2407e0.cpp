#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4D8A8[];
extern char lbl_27_data_4D8B8[];
void fn_27_23AAC4(void* p, const char* name);
}

struct fn27Obj {
    u8 pad_00[0x3C];
    void* unk3C;
    u8 pad_40[0x8];
    u32 unk48;
    u8 unk4C;
    u8 pad_4D[0x3];
    s32 unk50;
    s32 unk54;
    u8 unk58;
    u8 pad_59[0x3];
    s32 unk5C;
    s32 unk60;
};

extern "C" fn27Obj* fn_27_2407E0(fn27Obj* self) {
    fn_27_23AAC4(self, lbl_27_data_4D8A8);
    self->unk3C = lbl_27_data_4D8B8;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 5;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5C = 5;
    self->unk60 = 0;
    return self;
}
