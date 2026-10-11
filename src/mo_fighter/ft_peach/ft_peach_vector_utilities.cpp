#include <types.h>

struct PeachWideField {
    u8 unknown[8];
    u64 value;
};

extern "C" {
extern const f32 lbl_103_rodata_8;
void fn_103_9594(void* destination, f32 x, f32 y, f32 z);

void fn_103_C238(void* destination) {
    fn_103_9594(destination, lbl_103_rodata_8, lbl_103_rodata_8, lbl_103_rodata_8);
}

u64 fn_103_C24C(const PeachWideField* state) {
    return state->value;
}
}
