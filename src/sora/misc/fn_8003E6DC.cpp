#pragma force_active on
#include <mt/mt_matrix.h>
#include <revolution/OS/OSError.h>

extern "C" float mtSqrtf__Ff(float);
extern "C" const float lbl_805A1728;

extern "C" void fn_8003E6DC(const Matrix* m, Vec3f* out) {
    float x = m->m[0][0] * m->m[0][0] + m->m[1][0] * m->m[1][0] + m->m[2][0] * m->m[2][0];
    float y = m->m[2][1] * m->m[2][1] + (m->m[0][1] * m->m[0][1] + m->m[1][1] * m->m[1][1]);
    float z = m->m[2][2] * m->m[2][2] + (m->m[0][2] * m->m[0][2] + m->m[1][2] * m->m[1][2]);

    if (x < lbl_805A1728) {
        OSReport("Warning Scale x = %f", x);
        x = lbl_805A1728;
    }
    if (y < lbl_805A1728) {
        OSReport("Warning Scale y = %f", y);
        y = lbl_805A1728;
    }
    if (z < lbl_805A1728) {
        OSReport("Warning Scale z = %f", z);
        z = lbl_805A1728;
    }

    out->m_x = mtSqrtf__Ff(x);
    out->m_y = mtSqrtf__Ff(y);
    out->m_z = mtSqrtf__Ff(z);
}
