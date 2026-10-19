#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_108_rodata_8;

extern "C" void fn_108_D630(Vec2f* object, const Vec2f* value);

extern "C" void fn_108_D5F8(Vec2f* object) {
    Vec2f zero(lbl_108_rodata_8, lbl_108_rodata_8);
    fn_108_D630(reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(object) + 8), &zero);
}
