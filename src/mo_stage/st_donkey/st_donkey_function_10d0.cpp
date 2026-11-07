#include <string.h>
#pragma force_active on
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_50_data_0[];
extern "C" const float lbl_50_rodata_0[];
struct Item { unsigned char pad[0x20]; float a,b,c,d; unsigned char id,x,y,z; char name[0x28]; };
struct Stage_base { char pad[0x3c]; };
#define V(n) virtual void n();
#define V4(n) V(n##a) V(n##b) V(n##c) V(n##d)
class Stage : public Stage_base {
public:
 V4(a) V4(b) V4(c) V4(d) V4(e) V4(f) V4(g) V4(h) V4(i) V4(j)
 V4(k) V4(l) V4(m) V4(n) V4(o) V4(p) V4(q) V4(r) V4(s) V4(t)
 V4(u) V4(v) V4(w) V4(x) V4(y) V4(z) V4(aa) V4(ab) V4(ac) V4(ad)
 V4(ae) V4(af) V4(ag) V4(ah) V4(aj) V(ai)
 virtual void fn_50_15DC(int);
};
#define ENTRY(idx, ident, off, yoff, doff, kind) \
 p = self->items + idx; \
 memset(p,0,0x5c); \
 p->id=ident; p->x=0; p->y=0; p->z=1; \
 strcpy(p->name,data+off); \
 self->items->pad[6]=0xff; \
 p->a=rodata[0]; p->b=rodata[yoff]; \
 p->c=rodata[8]; p->d=rodata[doff]; \
 self->fn_50_15DC(kind);
struct Donkey : Stage { char pad2[0x3f4-0x40]; Item* items; };
extern "C" void fn_50_10D0(Donkey* self) {
 char* data;
 const float* rodata;
 rodata = lbl_50_rodata_0;
 data = lbl_50_data_0;
 Item* p = (Item*)__nwa__FUlQ25Heaps8HeapType(0x398,0x11);
 self->items=p;
 if(p) {
 ENTRY(0,0x3c,0x2d0,7,9,0x1b)
 ENTRY(1,0x3d,0x2dc,7,10,0x1c)
 ENTRY(2,0x3e,0x2e8,7,11,0x1d)
 ENTRY(3,0x3f,0x2f4,7,11,0x1e)
 ENTRY(4,0x40,0x300,7,12,0x1f)
 ENTRY(5,0x41,0x30c,13,14,0x20)
 ENTRY(6,0x42,0x318,7,12,0x21)
 ENTRY(7,0x43,0x324,7,9,0x22)
 ENTRY(8,0x44,0x330,7,12,0x23)
 ENTRY(9,0x45,0x33c,7,15,0x24)
 }
}