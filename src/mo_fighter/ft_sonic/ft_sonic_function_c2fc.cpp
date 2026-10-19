#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_123_rodata_8;

struct SonicVectorHolder {
    u32 header[2];
    Vec2f target;
};

extern "C" void fn_123_9574(Vec2f& dst, const Vec2f& src);

extern "C" void fn_123_C2FC(SonicVectorHolder* object) {
    Vec2f zero(lbl_123_rodata_8, lbl_123_rodata_8);
    fn_123_9574(object->target, zero);
}
