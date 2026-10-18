#pragma force_active on
extern "C" const float lbl_110_rodata_8;

struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void fn_110_B924(Vec3f* object) {
    object->m_x = lbl_110_rodata_8;
    object->m_y = lbl_110_rodata_8;
    object->m_z = lbl_110_rodata_8;
}
