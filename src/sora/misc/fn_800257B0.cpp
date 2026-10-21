#include <types.h>
#pragma force_active on
extern "C" {

struct SoraMenuEntry {
    u8 pad[0x4C];
    s32 value;
    u8 rest[0x18];
};

extern SoraMenuEntry lbl_80494EE8[];

void fn_800257B0(s32 index, s32 value) {
    lbl_80494EE8[index].value = value;
}
}
