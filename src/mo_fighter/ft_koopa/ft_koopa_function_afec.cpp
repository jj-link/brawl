#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_102_rodata_8;
extern "C" void fn_102_B024(Vec2f* dst, const Vec2f* src);

extern "C" void fn_102_AFEC(Vec2f* object) {
    Vec2f zero(lbl_102_rodata_8, lbl_102_rodata_8);
    fn_102_B024(object + 1, &zero);
}
