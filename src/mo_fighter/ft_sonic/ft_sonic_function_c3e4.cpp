#include <mt/mt_vector.h>
#pragma force_active on

extern "C" const float lbl_123_rodata_8;

extern "C" void fn_123_C3E4(Vec3f* object) {
    object->m_x = lbl_123_rodata_8;
    object->m_y = lbl_123_rodata_8;
    object->m_z = lbl_123_rodata_8;
}
