#pragma force_active on
#include <mt/mt_coll2d.h>

void clCircle2D::getAABBox(clAABBox2D& aabBox) const {
    float b;
    float a;
    a = m_centerPos.m_y + m_radius;
    b = m_centerPos.m_x + m_radius;
    float c = m_centerPos.m_y - m_radius;
    float d = m_centerPos.m_x - m_radius;
    aabBox.m_unk4 = a;
    aabBox.m_unk3 = b;
    aabBox.m_unk1 = d;
    aabBox.m_unk2 = c;
}
