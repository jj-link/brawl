#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8AD0[];
extern "C" unsigned char lbl_1_data_8BC4[];

struct Obj {
    void* vtable;
    const char* name;
    int unk;
};

extern "C" Obj* fn_1_36D48() {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x14, 0x2E);
    if (obj) {
        obj->vtable = lbl_1_data_8AD0;
        obj->name = (const char*)lbl_1_data_8BC4;
        obj->unk = 0;
    }
    return obj;
}
