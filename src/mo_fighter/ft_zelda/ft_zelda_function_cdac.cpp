#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_104_rodata_8;

struct ZeldaVecHolder {
    u32 header[2];
    Vec2f value;
};

extern "C" void fn_104_CDE4(Vec2f* dst, const Vec2f* src);

extern "C" void fn_104_CDAC(ZeldaVecHolder* object) {
    Vec2f zero(lbl_104_rodata_8, lbl_104_rodata_8);
    fn_104_CDE4(&object->value, &zero);
}
