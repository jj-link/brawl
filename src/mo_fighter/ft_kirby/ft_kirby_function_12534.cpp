#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_96_rodata_8;
extern "C" void fn_96_B890(Vec2f* dst, const Vec2f* src);

struct FtKirbyVec2Holder {
    u8 pad[8];
    Vec2f value;
};

extern "C" void fn_96_12534(FtKirbyVec2Holder* object) {
    Vec2f zero(lbl_96_rodata_8, lbl_96_rodata_8);
    fn_96_B890(&object->value, &zero);
}
