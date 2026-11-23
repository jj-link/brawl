#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_40_rodata_2C;

extern "C" int fn_40_8AF4(void* self, Vec3f* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_40_rodata_2C + result);
    out->m_x = *value;
    out->m_y = *value;
    out->m_z = *value;
    return result;
}
