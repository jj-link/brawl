#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Object {
    void* vtable;
    void* data;
    int unk8;
    int unkC;
};

extern "C" void* lbl_1_data_4C60;
extern "C" void* lbl_1_data_4CB8;

extern "C" Object* fn_1_10008() {
    Object* obj = static_cast<Object*>(__nw__FUlQ25Heaps8HeapType(0x18, 0x2E));
    if (obj) {
        obj->vtable = &lbl_1_data_4C60;
        obj->data = &lbl_1_data_4CB8;
        obj->unk8 = 0;
        obj->unkC = 0;
    }
    return obj;
}
