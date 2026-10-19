#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8980[];
extern "C" unsigned char lbl_1_data_89C0[];

struct Fn1_366E8Object {
    void* vtable;
    void* data;
    int value;
};

extern "C" Fn1_366E8Object* fn_1_366E8() {
    Fn1_366E8Object* obj =
        static_cast<Fn1_366E8Object*>(__nw__FUlQ25Heaps8HeapType(0xC, 0x2E));
    if (obj != 0) {
        obj->vtable = lbl_1_data_8980;
        obj->data = lbl_1_data_89C0;
        obj->value = 2;
    }
    return obj;
}
