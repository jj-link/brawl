#pragma force_active on
#pragma fp_contract on
typedef struct Vec4 { float x, y, z, w; } Vec4 __attribute__((aligned(16)));
typedef struct Mat4 { Vec4 c0, c1, c2, c3; } Mat4;
extern float lbl_805A3D80;
extern void fn_80282C78(Mat4 *, const Mat4 *);
inline void rot(Mat4 *m, const Vec4 *v, Vec4 *o)
{
    float nz = v->z, ny = v->y, nx = v->x;
    float x = nx * m->c0.x + ny * m->c1.x + nz * m->c2.x;
    float y = nx * m->c0.y + ny * m->c1.y + nz * m->c2.y;
    float z = nx * m->c0.z + ny * m->c1.z + nz * m->c2.z;
    m->c3.w = lbl_805A3D80;
    o->x = x;
    o->y = y;
    o->z = z;
}
void fn_802872F4(Mat4 *out, const Mat4 *in)
{
    Vec4 neg;
    fn_80282C78(out, in);
    neg.x = -in->c3.x;
    neg.y = -in->c3.y;
    neg.z = -in->c3.z;
    neg.w = -in->c3.w;
    rot(out, &neg, &out->c3);
}
