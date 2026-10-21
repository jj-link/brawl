#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern const char lbl_27_data_7B224[];
extern char lbl_27_data_7B234[];
extern const f32 lbl_27_rodata_6018;

struct FN_27_Task {
    char pad[0x3C];
    void* field_3C;
    s32 field_40;
    s32 field_44;
    s32 field_48;
    s32 field_4C;
    char pad50[0x10];
    s32 field_60;
    u8 field_64;
    char pad65[3];
    f32 field_68;
    f32 field_6C;
    char pad70[0x100];
    s32 field_170;
    s32 field_174;
    s32 field_178;
    s32 field_17C;
    s32 field_180;
    s32 field_184;
    s32 field_188;
    s32 field_18C;
    s32 field_190;
    s32 field_194;
};

FN_27_Task* fn_27_2C31A0(FN_27_Task* self, s32 a, s32 b, s32 c, s32 d) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_27_data_7B224, 0x12, 0xE, 0x6, true);
    self->field_40 = a;
    self->field_3C = lbl_27_data_7B234;
    self->field_44 = b;
    self->field_48 = c;
    self->field_4C = 0;
    self->field_170 = 0;
    self->field_174 = -1;
    self->field_178 = -1;
    self->field_17C = 0;
    self->field_180 = 0;
    self->field_184 = 0;
    self->field_188 = 0;
    self->field_18C = 0;
    self->field_190 = d;
    self->field_194 = 0;
    self->field_60 = -1;
    self->field_64 = 0;
    self->field_68 = lbl_27_rodata_6018;
    self->field_6C = lbl_27_rodata_6018;
    return self;
}

}
