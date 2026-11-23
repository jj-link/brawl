#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_82_rodata_10;

extern "C" int fn_82_3DE8(void* self, Vec3f* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_82_rodata_10 + result);
    out->m_x = *value;
    out->m_y = *value;
    out->m_z = *value;
    return result;
}
