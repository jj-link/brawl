#include <types.h>
#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A45C4;
extern const float lbl_805A45FC;
struct Matrix { char pad[0x20]; float m[3][4]; };
struct Obj { char pad[0x21]; u8 count; char pad22; s8 flag; char pad24[12]; float x,y,z,w; float a,b,c,d; };
struct Vec { float x,y,z,w; } __attribute__((aligned(16)));
extern "C" int fn_80306DA0(Matrix* m, Obj* p) {
    if ((int)p->count < 2) { p->flag = 0; return 0x1000000; }
    if (((unsigned)(-p->flag | p->flag) >> 31) == 0) {
        float z=p->z, y=p->y, x=p->x;
        p->a = z*m->m[0][2] + (x*m->m[0][0] + y*m->m[0][1]);
        p->b = z*m->m[1][2] + (x*m->m[1][0] + y*m->m[1][1]);
        p->c = z*m->m[2][2] + (x*m->m[2][0] + y*m->m[2][1]);
        p->d = lbl_805A45C4;
        p->flag = 1;
    }
    float a = p->a, b = p->b, c = p->c;
    Vec v;
    v.x = c*m->m[2][0] + (a*m->m[0][0] + b*m->m[1][0]);
    v.y = c*m->m[2][1] + (a*m->m[0][1] + b*m->m[1][1]);
    v.z = c*m->m[2][2] + (a*m->m[0][2] + b*m->m[1][2]);
    v.w = lbl_805A45C4;
    return (p->z*v.z + (p->x*v.x + p->y*v.y) < lbl_805A45FC) << 24;
}