#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_33D8;

extern "C" int getScrollDir__5StageFP5Vec3f(void* self, Vec3f* out) {
    int result = 0;
    const float* value = (const float*)((const char*)&lbl_27_rodata_33D8 + result);
    out->m_x = *value;
    out->m_y = *value;
    out->m_z = *value;
    return result;
}
