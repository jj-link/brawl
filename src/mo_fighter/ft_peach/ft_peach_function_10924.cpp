#include <types.h>
#pragma force_active on

extern "C" {

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern const char lbl_103_data_6820[];
extern char lbl_103_data_6830[];

struct FT_PeachTask {
    char pad[0x3C];
    void* field_3C;
    s32 field_40;
    s32 field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
    u8 field_58;
    u8 field_59;
    char pad_5A[4];
};

FT_PeachTask* fn_103_10924(FT_PeachTask* self, s32 a, s32 b) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_103_data_6820, 0x12, 0xE, 0x6, true);
    self->field_3C = lbl_103_data_6830;
    self->field_40 = a;
    self->field_44 = -1;
    self->field_50 = -1;
    self->field_54 = b;
    self->field_58 = 0;
    self->field_59 = 0;
    return self;
}

}
