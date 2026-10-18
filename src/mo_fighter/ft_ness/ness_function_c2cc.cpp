#pragma force_active on
struct Vec2f
{
    float m_x;
    float m_y;
};

struct Vec3f
{
    float m_x;
    float m_y;
    float m_z;
};

extern "C" void fn_101_C2CC(Vec3f* destination, const Vec2f* source, float z)
{
    destination->m_x = source->m_x;
    destination->m_y = source->m_y;
    destination->m_z = z;
}
