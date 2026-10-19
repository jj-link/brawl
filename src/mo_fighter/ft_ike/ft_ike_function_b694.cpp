#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_119_rodata_1C;

extern "C" void fn_119_B6CC(Vec2f& object, const Vec2f& value);

struct IkeVectorHolder {
    u32 header[2];
    Vec2f value;
};

extern "C" void fn_119_B694(IkeVectorHolder* object) {
    Vec2f zero(lbl_119_rodata_1C, lbl_119_rodata_1C);
    fn_119_B6CC(object->value, zero);
}
