#pragma force_active on
#pragma fp_contract on
#include <types.h>
typedef struct Vec4 { f32 x, y, z, w; } Vec4 __attribute__((aligned(16)));
typedef struct Mat { Vec4 c0, c1, c2; } Mat;
extern void fn_80282C78(Mat *, const Mat *);
extern const f32 lbl_805A3D08;
inline void copyMat(Mat *d, const Mat *s) {
    f32 x0=s->c0.x,y0=s->c0.y,z0=s->c0.z,w0=s->c0.w;
    f32 x1=s->c1.x,y1=s->c1.y,z1=s->c1.z,w1=s->c1.w;
    f32 x2=s->c2.x,y2=s->c2.y,z2=s->c2.z,w2=s->c2.w;
    d->c0.x=x0;d->c0.y=y0;d->c0.z=z0;d->c0.w=w0;
    d->c1.x=x1;d->c1.y=y1;d->c1.z=z1;d->c1.w=w1;
    d->c2.x=x2;d->c2.y=y2;d->c2.z=z2;d->c2.w=w2;
}
inline void mulVec(Vec4 *d, const Mat *m, const Vec4 *v) {
    f32 z=v->z,y=v->y,x=v->x;
    d->x=x*m->c0.x+y*m->c1.x+z*m->c2.x;
    d->y=x*m->c0.y+y*m->c1.y+z*m->c2.y;
    d->z=x*m->c0.z+y*m->c1.z+z*m->c2.z;
    d->w=lbl_805A3D08;
}
void fn_80282FE4(Mat *out, const Mat *in, const Mat *other) {
    Mat a,b;
    int i;
    fn_80282C78(&a,other);
    copyMat(&b,in);
    for (i=0;i<3;i++)
        mulVec(&(&out->c0)[i],&b,&(&a.c0)[i]);
}