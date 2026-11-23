#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_53_rodata_0;

extern "C" int fn_53_4004(void* self, Vec3f* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_53_rodata_0 + result);
    out->m_x = *value;
    out->m_y = *value;
    out->m_z = *value;
    return result;
}
