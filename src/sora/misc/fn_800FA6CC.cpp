#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern const f32 lbl_805A2678;
extern const f32 lbl_805A2684;
extern const f32 lbl_805A2690;

static inline f32 lowerClamp(f32 value, f32 lo) {
    return nw4r::math::FSelect(value - lo, value, lo);
}

extern "C" void fn_800FA6CC(u8* self) {
    u8 flags = self[0x100];
    if (!((flags >> 7) & 1)) {
        f32 zero = lbl_805A2678;
        f32 t;
        f32 limit = zero;
        self[0x100] = flags | 0x80;
        t = (f32)*(u16*)(self + 0x27AA) - lbl_805A2690;
        *(f32*)(self + 0xFC) = nw4r::math::FSelect(zero - t, t, zero);
        if (*(u16*)(self + 0x13A4) != 0) {
            limit = lbl_805A2684;
        }
        *(f32*)(self + 0xFC) = lowerClamp(*(f32*)(self + 0xFC), limit);
    }
}