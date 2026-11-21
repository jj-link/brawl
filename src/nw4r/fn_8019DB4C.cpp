#include <types.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
static inline void set_scale(u32 reg, u32 size, u8 bias, u8 wrap) {
    u32 reg_value = reg << 24;
    u32 wrap_value = (u32)wrap << 17;
    u32 bias_value = (u32)bias << 16;
    u32 size_value = size - 1;
    u32 combined = size_value | bias_value;
    u32 combined2 = wrap_value | combined;
    u32 value = combined2 | reg_value;
    GX_BP_LOAD_REG(value);
}
extern "C" void fn_8019DB4C(u32 coord, u32 s, u8 sbias, u8 swrap, u32 t, u8 tbias, u8 twrap) {
    GX_BP_LOAD_REG(0xFE03FFFF);
    set_scale(coord * 2 + 0x30, s, sbias, swrap);
    set_scale(coord * 2 + 0x31, t, tbias, twrap);
}