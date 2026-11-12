#include <types.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void fn_8003E6DC(const Matrix* mtx, Vec3f* vec);
float mtSqrtf__Ff(float);
float rsqrtf__Ff(float);
double atan2(double, double);
extern const float lbl_805A1728;
extern const float lbl_805A1734;

void fn_8003F2AC(const Matrix* m, Vec3f* scale, Vec3f* rot, Vec3f* pos) {
    float temp_f2 = m->m[2][3];
    pos->m_y = (m->m[1][3]);
    pos->m_x = m->m[0][3];
    pos->m_z = temp_f2;
    fn_8003E6DC(m, scale);
    Matrix t = *m;
    float invX = rsqrtf__Ff(t.m[0][0]*t.m[0][0] + t.m[1][0]*t.m[1][0] + t.m[2][0]*t.m[2][0]);
    float invY = rsqrtf__Ff(t.m[0][1]*t.m[0][1] + t.m[1][1]*t.m[1][1] + t.m[2][1]*t.m[2][1]);
    float invZ = rsqrtf__Ff(t.m[0][2]*t.m[0][2] + t.m[1][2]*t.m[1][2] + t.m[2][2]*t.m[2][2]);
    t.m[0][0] *= invX; t.m[1][0] *= invX; t.m[2][0] *= invX;
    t.m[0][1] *= invY; t.m[1][1] *= invY; t.m[2][1] *= invY;
    t.m[0][2] *= invZ; t.m[1][2] *= invZ; t.m[2][2] *= invZ;
    float len = mtSqrtf__Ff(t.m[0][0]*t.m[0][0] + t.m[1][0]*t.m[1][0]);
    if (len > lbl_805A1734) {
        float b = t.m[2][2];
        rot->m_x = atan2(t.m[2][1], b);
        rot->m_y = atan2(-t.m[2][0], len);
        float c = t.m[0][0];
        rot->m_z = atan2(t.m[1][0], c);
    } else {
        rot->m_x = atan2(-t.m[1][2], t.m[1][1]);
        rot->m_y = atan2(-t.m[2][0], len);
        rot->m_z = lbl_805A1728;
    }
}
}
