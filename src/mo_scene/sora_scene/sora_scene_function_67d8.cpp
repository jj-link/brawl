#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

extern char lbl_1_data_15D8[];
extern char lbl_1_data_1658[];

struct Obj {
    void* vt;
    void* p;
    int a;
    int b;
};

extern "C" void* fn_1_67D8() {
    Obj* o = (Obj*)__nw__FUlQ25Heaps8HeapType(0x10, 0x2E);
    if (o) {
        o->vt = lbl_1_data_15D8;
        o->p = lbl_1_data_1658;
        o->a = 0;
        o->b = 0;
    }
    return o;
}
