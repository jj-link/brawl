#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_112_rodata_8;

#pragma dont_inline on
extern "C" Vec2f& fn_112_CC3C(Vec2f& object, const Vec2f& value);
#pragma dont_inline reset

extern "C" void fn_112_CC04(Vec2f* object) {
    Vec2f zero(lbl_112_rodata_8, lbl_112_rodata_8);
    fn_112_CC3C(object[1], zero);
}
