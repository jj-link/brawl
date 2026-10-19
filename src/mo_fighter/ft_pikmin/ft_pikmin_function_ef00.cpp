#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_C;
extern "C" void fn_113_BC00(Vec2f* dst, const Vec2f* src);

extern "C" void fn_113_EF00(Vec2f* object) {
    Vec2f zero(lbl_113_rodata_C, lbl_113_rodata_C);
    fn_113_BC00(object + 1, &zero);
}
