#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_125_rodata_8;
extern "C" void fn_125_D6D8(Vec2f* dst, const Vec2f* src);

struct WolfVec2Holder {
    u32 header[2];
    Vec2f value;
};

extern "C" void fn_125_D6A0(WolfVec2Holder* object) {
    Vec2f zero(lbl_125_rodata_8, lbl_125_rodata_8);
    fn_125_D6D8(&object->value, &zero);
}
