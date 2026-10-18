#pragma force_active on
struct Vec3f {
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void fn_119_7C40(Vec3f* object, const Vec3f* value) {
    object->m_x = value->m_x;
    object->m_y = value->m_y;
    object->m_z = value->m_z;
}
