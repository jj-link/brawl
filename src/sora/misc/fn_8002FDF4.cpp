#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct HeapObj {
    int f0;
    int f4;
    char pad0x08[0x28];
    char f30;
    char pad0x31[0x7];
    int f38;
    char pad0x3C[0x28];
    char f64;
    char pad0x65[0x3];
    char f68;
    char pad0x69[0x3];
    int f6C;
};

extern void* lbl_805A0070;

extern "C" void fn_8002FDF4() {
    HeapObj* obj = static_cast<HeapObj*>(__nw__FUlQ25Heaps8HeapType(0x70, 1));
    if (obj != 0) {
        obj->f68 = 0;
        obj->f6C = 0xC8;
        obj->f4 = 0;
        obj->f30 = 0;
        obj->f38 = 0;
        obj->f64 = 0;
    }
    lbl_805A0070 = obj;
}
