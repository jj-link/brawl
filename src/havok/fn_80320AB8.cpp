#pragma force_active on
#pragma fp_contract on

extern float lbl_805A4750;
extern float lbl_805A4754;
extern float lbl_805A4758;

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));

struct Plane {
    float x, y, z, w;
    float d;
    V4* a;
    char pad18[0xC];
    V4* b;
    char pad28[0xC];
    V4* c;
};

extern "C" void fn_80320AB8(Plane* p) {
    V4* a = p->a;
    V4* b = p->b;
    V4* c = p->c;
    V4 e1, e2;
    e1.x = a->x - b->x; e1.y = a->y - b->y; e1.z = a->z - b->z; e1.w = a->w - b->w;
    e2.x = b->x - c->x; e2.y = b->y - c->y; e2.z = b->z - c->z; e2.w = b->w - c->w;
    float nz, ny, nx;
    nx = e1.y * e2.z - e1.z * e2.y;
    ny = e1.z * e2.x - e1.x * e2.z;
    nz = e1.x * e2.y - e1.y * e2.x;
    float l = nx * nx + ny * ny + nz * nz;
    float r = lbl_805A4750;
    p->x = nx;
    p->y = ny;
    p->z = nz;
    p->w = r;
    if (l != r) {
        if (l <= r) {
            union { int i; float f; } u;
            u.i = 0x7f800000;
            r = u.f;
        } else {
            double d = __frsqrte(l);
            float e = (float)d;
            r = lbl_805A4754 * e * (lbl_805A4758 - e * (l * e));
        }
    }
    p->x *= r;
    p->y *= r;
    p->z *= r;
    p->w *= r;
    V4* q = p->a;
    p->d = p->x * q->x + p->y * q->y + p->z * q->z;
}
