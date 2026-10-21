#pragma force_active on
#include <types.h>

struct Entry {
    u8 pad[0x4c];
    s32 value;
    u8 rest[0x68 - 0x50];
};

extern Entry lbl_80494EE8[];

extern "C" s32 fn_80025704(s32 index) {
    return lbl_80494EE8[index].value;
}
