#include <revolution/MTX/mtx.h>
#pragma force_active on

extern const float lbl_805A3D48;
extern const float lbl_805A3D4C;

void fn_80285A6C(Mtx m, const Quaternion *q)
{
    float x2 = q->x + q->x;
    float y2 = q->y + q->y;
    float z2 = q->z + q->z;
    float xx = x2 * q->x;
    float xy = y2 * q->x;
    float yy = y2 * q->y;
    float zz = z2 * q->z;
    float xz = z2 * q->x;
    float yz = z2 * q->y;
    float wx = x2 * q->w;
    float wy = y2 * q->w;
    float wz = z2 * q->w;

    m[0][0] = lbl_805A3D48 - (yy + zz);
    m[0][3] = lbl_805A3D4C;
    m[1][3] = lbl_805A3D4C;
    m[2][3] = lbl_805A3D4C;

    m[0][1] = xy + wz;
    m[1][0] = xy - wz;
    m[1][1] = lbl_805A3D48 - (xx + zz);
    m[2][2] = lbl_805A3D48 - (xx + yy);
    m[0][2] = xz - wy;
    m[1][2] = yz + wx;
    m[2][0] = xz + wy;
    m[2][1] = yz - wx;
}
