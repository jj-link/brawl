#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_8;
extern "C" void fn_110_B860(Vec2f* dst, const Vec2f* src);

extern "C" void fn_110_B828(u8* self) {
    Vec2f zero(lbl_110_rodata_8, lbl_110_rodata_8);
    fn_110_B860((Vec2f*)(self + 8), &zero);
}
