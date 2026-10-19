#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const float lbl_109_rodata_8;
void fn_109_B180(Vec2f* dst, const Vec2f* src);

void fn_109_B148(void* self) {
    Vec2f value;
    value.m_x = lbl_109_rodata_8;
    value.m_y = lbl_109_rodata_8;
    fn_109_B180((Vec2f*)((char*)self + 8), &value);
}
}
