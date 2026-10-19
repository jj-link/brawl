#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_121_rodata_C;
extern "C" void fn_121_DAE8(Vec2f* dst, const Vec2f* src);

extern "C" void fn_121_DAB0(char* self) {
    Vec2f zero;
    zero.m_x = lbl_121_rodata_C;
    zero.m_y = lbl_121_rodata_C;
    fn_121_DAE8(reinterpret_cast<Vec2f*>(self + 8), &zero);
}
