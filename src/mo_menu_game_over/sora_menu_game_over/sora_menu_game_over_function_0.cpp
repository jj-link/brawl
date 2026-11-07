#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_12_D8(void* p);
extern "C" void fn_800B96E8(void* p, int v);

struct Params {
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    int f;
};

struct Obj {
    unsigned char pad0[0x44];
    int f44;
    unsigned char pad48[0x58 - 0x48];
    Params p;
    unsigned char pad70[0x12c - 0x70];
    int f12c;
};

extern "C" Obj* fn_12_0(Params params, int arg) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x130, 0x2a);
    if (obj) {
        obj = (Obj*)fn_12_D8(obj);
    }
    obj->p = params;
    obj->p.c /= 10;
    obj->p.d /= 10;
    fn_800B96E8((char*)obj + 0x70, 0xf0);
    obj->f44 = 0;
    obj->f12c = arg;
    return obj;
}
