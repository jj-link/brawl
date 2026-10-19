#include <types.h>
#pragma force_active on

extern const float lbl_41_rodata_18;

struct Self {
    u8 pad0[0xbc];
    s32 level;
};

extern "C" float fn_41_3678(Self* self, u32 level);
extern "C" void fn_41_3C04(Self* self);

extern "C" float fn_41_37C8(Self* self, u32 level) {
    if (level < 1 || level > 5) {
        return lbl_41_rodata_18;
    }
    self->level = level;
    float result = fn_41_3678(self, level);
    fn_41_3C04(self);
    return result;
}
