#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad[4];
    s32 value;
    u8 rest[0x60];
};

extern "C" extern Entry lbl_80494EE8[];

extern "C" s32 fn_800256A4(s32 index) {
    return lbl_80494EE8[index].value;
}
