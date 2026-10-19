#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_4140[];
extern "C" char lbl_1_data_4168[];

struct fnObj {
    void* vtbl;
    void* ptr;
    int a;
    int b;
};

extern "C" void fn_1_C9C4() {
    fnObj* obj = (fnObj*)__nw__FUlQ25Heaps8HeapType(0x10, 0x2e);
    if (obj) {
        obj->vtbl = lbl_1_data_4140;
        obj->ptr = lbl_1_data_4168;
        obj->a = 0;
        obj->b = 0;
    }
}
