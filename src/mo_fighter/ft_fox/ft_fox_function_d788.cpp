#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_97_rodata_8;

extern "C" void fn_97_D7C0(Vec2f* dst, const Vec2f* src);

extern "C" void fn_97_D788(Vec2f* object) {
    Vec2f zero(lbl_97_rodata_8, lbl_97_rodata_8);
    fn_97_D7C0(object + 1, &zero);
}
