#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
    u8 pad[0x1d - 0xc];
    u8 unk1D;
};

extern "C" void fn_80192814(Obj **arg0, u32 *arg1, u8 *arg2) {
    Obj *temp_r6;
    s32 temp_r0;
    u32 var_r0;

    if (arg1 != 0) {
        temp_r6 = *arg0;
        temp_r0 = temp_r6->unk8;
        if (temp_r0 != 0) {
            var_r0 = (u32)temp_r6 + temp_r0;
        } else {
            var_r0 = 0;
        }
        *arg1 = var_r0;
    }
    if (arg2 != 0) {
        *arg2 = (*arg0)->unk1D;
    }
}
