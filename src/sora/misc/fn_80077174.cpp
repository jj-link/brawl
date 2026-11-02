#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on

extern const f32 lbl_805A1AC8;
extern const f32 lbl_805A1ACC;
extern "C" void fn_801BD4A4(void* self, s32 idx, f32 val);

extern "C" void fn_80077174(void* self, s32 unused, f32 x, s32 flag) {
    f32 delta = lbl_805A1AC8 - x;
    f32 clamped = nw4r::math::FSelect(delta, x, lbl_805A1AC8);
    f32 lower = lbl_805A1ACC;
    *(f32*)((char*)self + 0x710) = nw4r::math::FSelect(lower - clamped, lower, clamped);
    if (flag != 0) {
        char* p = (char*)self;
        for (u32 i = 0; i < 0x20; i++) {
            void* obj = *(void**)(p + 0x2D4);
            f32 value = *(f32*)((char*)self + 0x710);
            if (obj != 0) {
                fn_801BD4A4(obj, 0, value);
            }
            p += 0x20;
        }
    }
}
