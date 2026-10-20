#include <types.h>
#pragma force_active on

struct fn_27_Flags {
    u8 unk0 : 7;
    u8 flag : 1;
};

extern "C" {
void fn_27_1CB00(u8* self, u32 value) {
    ((fn_27_Flags*)(self + 0x164))->flag = value;
}
}
