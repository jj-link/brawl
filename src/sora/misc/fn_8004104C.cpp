#include <mt/mt_vector.h>
#pragma force_active on

extern const float lbl_805A17B4;

extern "C" int fn_8004104C(const float* a, const float* b) {
    Vec2f n, w, d, d2, f, e, w0;

    d.m_x = a[2] - a[0];
    d.m_y = a[3] - a[1];
    w0.m_x = b[0] - a[0];
    w0.m_y = b[1] - a[1];
    d2.m_y = d.m_y;
    d2.m_x = d.m_x;

    __memcpy(&f, &d, sizeof(Vec2f));
    __memcpy(&e, &d2, sizeof(Vec2f));

    float ny = f.m_x;
    double nx = -e.m_y;
    n.m_x = -e.m_y;
    n.m_y = ny;

    __memcpy(&w, &w0, sizeof(Vec2f));

    return ((float)nx * w.m_x + n.m_y * w.m_y) > lbl_805A17B4;
}
