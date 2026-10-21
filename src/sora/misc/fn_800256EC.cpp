#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad[0x64];
    f32 value;
};

extern "C" {
extern Entry lbl_80494EE8[];

f32 fn_800256EC(s32 index) {
    return lbl_80494EE8[index].value;
}
}
