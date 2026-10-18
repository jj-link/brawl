#include <types.h>
#pragma force_active on

struct SoraMenuEntry {
    u8 pad[12];
    s32 value;
    u8 rest[4];
};

extern SoraMenuEntry lbl_2_rodata_B40[];

extern "C" s32 fn_2_25BA8(s32 index) {
    return lbl_2_rodata_B40[index].value;
}
