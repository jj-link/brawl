#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_93_rodata_C;
extern "C" void fn_93_DAEC(Vec2f* dst, const Vec2f* src);

extern "C" void fn_93_DAB4(u8* obj) {
    Vec2f zero(lbl_93_rodata_C, lbl_93_rodata_C);
    fn_93_DAEC(reinterpret_cast<Vec2f*>(obj + 8), &zero);
}
