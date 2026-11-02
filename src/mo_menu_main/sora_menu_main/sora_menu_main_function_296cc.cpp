#pragma force_active on
#include <mu/mu_msg.h>

extern "C" {
s32 fn_2_25B90(s32 idx);
s32 fn_2_25BA8(s32 idx);
s32 fn_2_25BD8(char* buf, s32* out, s32 c, s32 d, s32 e);
void fn_800B92D8(void* msg, u32 index, char* buf, u32 len);
extern char lbl_2_data_34DC;
}

struct Obj {
    char pad0[0x66C];
    s32 unk66C;
    char pad1[0x8];
    MuMsg* msg;
};

extern "C" void fn_2_296CC(Obj* self, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x80];
    s32 sp8;
    s32 var;
    s32 temp;

    self->msg->printIndex(arg3 + self->unk66C + 4, fn_2_25BA8(arg1));
    temp = fn_2_25B90(arg1);
    switch (temp) {
    case 2:
        var = 0x5F5E0FF;
        break;
    case 6:
        var = 0x5B8D7F;
        break;
    default:
        var = 0x5F5E0FF;
        break;
    }
    fn_800B92D8(self->msg, arg3 + self->unk66C + 0xB, buf, fn_2_25BD8(buf, &sp8, arg1, arg2, var) + 1);
    if (sp8 != -1) {
        self->msg->printIndex(arg3 + self->unk66C + 0x12, (u32)sp8);
        return;
    }
    self->msg->printf(arg3 + self->unk66C + 0x12, &lbl_2_data_34DC);
}
