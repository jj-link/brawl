#include <types.h>
#pragma force_active on

struct obj_29FE94 {
    u32 unk0;
    u32 unk4_hi : 24;
    s32 unk4_lo : 8;
};

extern "C" s32 fn_27_29FE94(const obj_29FE94* obj) {
    return obj->unk4_lo;
}
