#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
extern const float lbl_805A1500;
extern const float lbl_805A150C;
extern const float lbl_805A1510;
extern "C" void fn_8002503C(const Vec2f* p, Vec2f* out, float width, float height) {
    const Vec2f& a = p[0];
    const Vec2f& b = p[1];
    float dx = b.m_x - a.m_x;
    float dy = b.m_y - a.m_y;
    if ((float)(double)nw4r::ut::Abs(dx) < lbl_805A150C) {
        out->m_x = lbl_805A1510 * width;
        if (dy < lbl_805A1500) out->m_y = lbl_805A1500;
        else out->m_y = height;
        return;
    }
    if (lbl_805A1500 < dx) {
        *out = a + (b - a) * ((width - a.m_x) / dx);
        if (lbl_805A1500 <= out->m_y) {
            if (out->m_y < height) goto done;
        }
        goto fallback;
    } else {
        *out = a + (b - a) * (-a.m_x / dx);
        if (lbl_805A1500 <= out->m_y && out->m_y < height) return;
    }
fallback:
    if (lbl_805A1500 < dy) {
        *out = a + (b - a) * ((height - a.m_y) / dy);
    } else {
        *out = a + (b - a) * (-a.m_y / dy);
    }
done:
    ;
}