#include <types.h>
extern "C" void fn_8019DFAC(void*, void*, int);
struct A {
 u32 flags; u8 data[64];
 void operator=(const A& r) {
 if (this == &r) return;
 flags = r.flags;
 fn_8019DFAC(data, (void*)r.data, 64);
 }
};
struct B { u8 a,b,c,d; };
struct C {
 u8 a,b,c,d,e,f,g,h,i,j,k,l;
 C& operator=(const C& r) {
 u8 x=r.a,y=r.b; a=x;b=y;
 x=r.c;y=r.d;c=x;d=y;
 x=r.e;y=r.f;e=x;f=y;
 x=r.g;y=r.h;g=x;h=y;
 x=r.i;i=x;x=r.j;j=x;x=r.k;k=x;x=r.l;l=x;
 return *this;
 }
};
struct Hdr { u16 n0,n1; A* p4; B* p8; C* pC; };
#pragma force_active on
extern "C" int fn_801B6708(Hdr* a, Hdr* b) {
 if(a->n0<b->n0 || a->n1<b->n1)return 0;
 for(u32 i=0;i<b->n0;i++){
 A* d;
 const A& s=b->p4[i];
 if(s.flags&4) {
 d = &a->p4[i];
 if(d != &s) {
 d->flags = s.flags;
 fn_8019DFAC(d->data, (void*)s.data, 64);
 }
 }
 else a->p4[i].flags &= ~4;
 a->p8[i]=b->p8[i];
 }
 for(u32 j=0;j<b->n1;j++) a->pC[j]=b->pC[j];
 return 1;
}