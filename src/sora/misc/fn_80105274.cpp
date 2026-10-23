#include <mu/mu_msg.h>
#pragma force_active on

extern "C" {

extern char lbl_8059E5C4;

struct Unk {
    char pad_0[0x0C];
    MuMsg* m_msg;
};

void fn_80105274(Unk* self, s32 value) {
    s32 a = -value;
    MuMsg* msg = self->m_msg;
    s32 t = value & ((s32)(a & ~value) >> 0x1F);
    msg->printf(0x0B, &lbl_8059E5C4, (t < 0x3E7) ? t : 0x3E7);
}

}
