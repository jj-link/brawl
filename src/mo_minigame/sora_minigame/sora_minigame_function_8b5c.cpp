#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_20_8060(void*);
extern "C" void fn_20_8C30(void*, void*);
extern "C" void* fn_20_307C(void*);
extern "C" void fn_20_6A3C(void*);
extern "C" void fn_8027CE3C(void*, int);

struct Vec {
    void** data;
    int size;
    int raw;
};

struct SoraObj {
    u8 pad0[0x370];
    u8 count;
    u8 pad1[0x4E8 - 0x371];
    Vec v;
};

extern "C" void fn_20_8B5C(void* arg0) {
    SoraObj* o = (SoraObj*)arg0;
    void* a;
    int i;
    fn_20_8060(arg0);
    fn_20_8C30(arg0, *o->v.data);
    for (i = 0; i < (int)(o->count - 1); i++) {
        if (o->v.size < 0x14) {
            a = __nw__FUlQ25Heaps8HeapType(0x78, 0x2A);
            if (a) {
                a = fn_20_307C(a);
            }
            fn_20_6A3C(a);
            if (o->v.size == (o->v.raw & 0x3FFFFFFF)) {
                fn_8027CE3C(&o->v, 4);
            }
            o->v.data[o->v.size++] = a;
        }
    }
}
