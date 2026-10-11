#include <mt/mt_vector.h>

extern "C" const float lbl_111_rodata_8;

extern "C" Vec3f fn_111_A6EC(void*) {
    return Vec3f(lbl_111_rodata_8, lbl_111_rodata_8, lbl_111_rodata_8);
}

extern "C" Vec2f fn_111_A704(const void* object) {
    return *reinterpret_cast<const Vec2f*>(static_cast<const u8*>(object) + 8);
}
