#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_122_rodata_C;
extern "C" void fn_122_12CC4(Vec2f* dst, const Vec2f* src);

extern "C" void fn_122_12C8C(u8* object) {
    Vec2f zero(lbl_122_rodata_C, lbl_122_rodata_C);
    fn_122_12CC4((Vec2f*)(object + 0x8), &zero);
}
