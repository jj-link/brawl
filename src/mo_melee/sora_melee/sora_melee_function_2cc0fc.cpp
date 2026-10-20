#include <types.h>
#pragma force_active on

struct Slot {
    u32* info;
    s16 value;
    s16 pad;
};

extern "C" bool fn_27_2CC0FC(u8* self, u32 id, s32 delta) {
    if (delta != 0) {
        Slot* slots = (Slot*)self;
        s32 count = *(s32*)(self + 0x2800);
        s32 i;
        for (i = 0; i < count; i++) {
            if (id == *slots[i].info) {
                break;
            }
        }
        if (i < count) {
            s32 v = delta + slots[i].value;
            if (v >= 0) {
                slots[i].value = (s16)v;
                self[0x3c09] |= 0xc;
                return true;
            }
        }
    }
    return false;
}
