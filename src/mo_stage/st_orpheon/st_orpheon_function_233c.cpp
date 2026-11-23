#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_55_rodata_0;

extern "C" int fn_55_233C(void* self, Vec3f* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_55_rodata_0 + result);
    out->m_x = *value;
    out->m_y = *value;
    out->m_z = *value;
    return result;
}
