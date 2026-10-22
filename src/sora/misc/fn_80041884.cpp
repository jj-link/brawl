#pragma force_active on
typedef float f32;
struct Vec3f { f32 x,y,z; };
extern "C" void fn_80041884(Vec3f* a, Vec3f* b, Vec3f* out, f32 t) {
    f32 bx, by, ay, dx, ax, dy, tdx, tdy;
    bx = b->x;
    ax = a->x;
    dx = bx - ax;
    by = b->y;
    ay = a->y;
    dy = by - ay;
    tdx = t * dx;
    f32 rx = ax + tdx;
    tdy = t * dy;
    f32 ry = ay + tdy;
    f32 rz = a->z + t * (b->z - a->z);
    out->x = rx;
    out->y = ry;
    out->z = rz;
}
