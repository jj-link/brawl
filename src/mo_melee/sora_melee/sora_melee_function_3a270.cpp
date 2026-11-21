#include <types.h>
#pragma force_active on
extern const float lbl_27_rodata_49C;
struct Quad { u32 a,b,c,d; };
struct Vec { float x,y,z; };
struct Bits38 { unsigned o0:16,o1:1,o2:2,o3:3,o4:1,o5:1,o6:1,o7:1,o8:1,o9:5; };
union W38 { u32 raw; Bits38 b; };
struct Entry {
 u32 a; float b,c,d,e; Quad q; Vec v;
 unsigned m0:27,m1:5;
 unsigned n0:2,n1:5,n2:15,n3:10;
 W38 w38;
 unsigned p0:1,p1:31; char pad[0x20]; int value; u8 active;
};
struct Flags { unsigned x0:5,x1:2,x2:5,x3:3,x4:1,x5:1,x6:5,x7:1,x8:9; };
union FlagsU { u32 raw; Flags b; };
class Class_C80 { public: virtual void fn_27_FEE4(); virtual Entry* fn_27_FF68(int); };
class FirstCall { public: virtual void fn_27_FEE4(); virtual Entry* fn_27_FF68(); };
class Class6 { public: virtual void fn_27_FEE4(); virtual Entry* fn_27_FF68(int, u32, u32, u32, float, float); };
struct Object { char pad[0x34]; Class_C80* list; };
struct Input { u32 a; Quad q; Vec v; FlagsU flags; };
extern "C" void fn_27_3A270(Object* obj, int index, int value, Input* in) {
 u32 q4; u32 q3; u32 q2; u32 q1;
 float h; float g; float f;
 ((FirstCall*)obj->list)->fn_27_FF68()->value = value;
 Entry* p = obj->list->fn_27_FF68(index);
 float e = lbl_27_rodata_49C;
 p->a=in->a;
 q1=in->q.a;
 float t=p->d;
 q2=in->q.b;
 p->c=t;
 q3=in->q.c;
 p->b=t;
 q4=in->q.d;
 p->e=e;
 f=in->v.x; p->q.a=q1;
 g=in->v.y; p->q.b=q2;
 h=in->v.z; p->q.c=q3;
 FlagsU fu = in->flags; Flags x = fu.b; p->q.d=q4;
 p->v.x=f; p->v.y=g; p->v.z=h;
 p->m0=0; p->m1=x.x0;
 p->n0=x.x1; p->n1=x.x2; p->n2=0;
 W38 w; w.raw = p->w38.raw;
 w.b.o0=0; w.b.o1=1;
 p->p0=1;
 w.b.o2=0; w.b.o3=x.x3; w.b.o4=x.x7;
 u32 acc = w.raw;
 w.b.o5=0; w.b.o6=x.x4; w.b.o7=x.x5; w.b.o8=0; w.b.o9=x.x6;
 p->w38 = w;
 Entry* q = ((Class6*)obj->list)->fn_27_FF68(index, acc, fu.raw, q1, g, f);
 q->active = 1;
}
