#include <types.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on

typedef struct Vec4A { f32 x,y,z,w; } Vec4A __attribute__((aligned(16)));
typedef struct Mat3A { Vec4A a,b,c; } Mat3A;
typedef struct Mat4A { Vec4A a,b,c,d; } Mat4A;
typedef struct Arg { Vec4A pos, quat, scale; } Arg;
extern const f32 lbl_805A3D28;
extern void fn_80285A6C(Mtx, const Quaternion *);
extern void fn_80282CD4(Mat3A *, const Mat3A *, const Mat3A *);
extern void fn_802871F4(float *, float *);

void fn_80284DB0(const Arg *arg, float *out)
{
    Mat3A rot;
    Mat3A scale;
    Mat3A result;
    Mat4A combined;
    f32 scratch[8] __attribute__((aligned(16)));
    Mat3A *p;
    f32 sx,sy,sz;
    f32 z,y,x;
    f32 l,k,j,i,h,g,f,e,d,c,b,a;
    fn_80285A6C((f32 (*)[4])&rot, (const Quaternion *)&arg->quat);
    p = &scale;
    sz = arg->scale.z;
    p->a.y=lbl_805A3D28;
    sy = arg->scale.y;
    p->a.z=lbl_805A3D28;
    sx = arg->scale.x;
    scratch[7]=lbl_805A3D28; scratch[6]=lbl_805A3D28;
    scratch[5]=lbl_805A3D28; scratch[4]=lbl_805A3D28;
    scratch[3]=lbl_805A3D28; scratch[2]=lbl_805A3D28;
    scratch[1]=lbl_805A3D28; scratch[0]=lbl_805A3D28;
    scale.a.y=lbl_805A3D28; scale.a.z=lbl_805A3D28; scale.a.w=lbl_805A3D28;
    scale.b.x=lbl_805A3D28; scale.b.z=lbl_805A3D28; scale.b.w=lbl_805A3D28;
    scale.c.x=lbl_805A3D28; scale.c.y=lbl_805A3D28; scale.c.w=lbl_805A3D28;
    scale.a.x=sx; scale.b.y=sy; scale.c.z=sz;
    fn_80282CD4(&result, &rot, p);
    a=result.a.x; b=result.a.y; c=result.a.z; d=result.a.w;
    e=result.b.x; f=result.b.y; g=result.b.z; h=result.b.w;
    i=result.c.x; j=result.c.y; k=result.c.z; l=result.c.w;
    x=arg->pos.x; y=arg->pos.y; z=arg->pos.z;
    combined.a.x=a; combined.a.y=b; combined.a.z=c; combined.a.w=d;
    combined.b.x=e; combined.b.y=f; combined.b.z=g; combined.b.w=h;
    combined.c.x=i; combined.c.y=j; combined.c.z=k; combined.c.w=l;
    combined.d.x=x; combined.d.y=y; combined.d.z=z; combined.d.w=arg->pos.w;
    fn_802871F4((float *)&combined, out);
}