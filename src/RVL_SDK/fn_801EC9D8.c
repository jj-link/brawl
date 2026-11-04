#include <revolution/MTX/mtx.h>
#pragma force_active on

void fn_801ED008(const Vec* in, Vec* out);
void fn_801ED0B0(const Vec* a, const Vec* b, Vec* prod);

void fn_801EC9D8(Mtx out, const Vec* p, const Vec* up, const Vec* t) {
    Vec zAxis;
    Vec xAxis;
    Vec yAxis;

    zAxis.x = p->x - t->x;
    zAxis.y = p->y - t->y;
    zAxis.z = p->z - t->z;
    fn_801ED008(&zAxis, &zAxis);
    fn_801ED0B0(up, &zAxis, &xAxis);
    fn_801ED008(&xAxis, &xAxis);
    fn_801ED0B0(&zAxis, &xAxis, &yAxis);

    out[0][0] = xAxis.x;
    out[0][1] = xAxis.y;
    out[0][2] = xAxis.z;
    out[0][3] = -(p->x * xAxis.x + p->y * xAxis.y + p->z * xAxis.z);
    out[1][0] = yAxis.x;
    out[1][1] = yAxis.y;
    out[1][2] = yAxis.z;
    out[1][3] = -(p->x * yAxis.x + p->y * yAxis.y + p->z * yAxis.z);
    out[2][0] = zAxis.x;
    out[2][1] = zAxis.y;
    out[2][2] = zAxis.z;
    out[2][3] = -(p->x * zAxis.x + p->y * zAxis.y + p->z * zAxis.z);
}
