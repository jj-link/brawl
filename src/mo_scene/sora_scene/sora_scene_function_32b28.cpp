#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8068[];
extern "C" unsigned char lbl_1_data_8578[];
extern "C" unsigned int lbl_1_bss_1B5C;
extern "C" unsigned int lbl_1_bss_1B60;

struct Pair {
    unsigned int first;
    unsigned int second;
};

extern "C" void fn_80018280(Pair*, int);
extern "C" void fn_1_33DBC(unsigned int, unsigned int);

struct Object {
    void* vtable;
    void* name;
    unsigned int field8;
    unsigned char padding[24];
    unsigned int field24;
};

extern "C" Object* fn_1_32B28() {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x28, 0x2E);
    if (obj) {
        obj->vtable = lbl_1_data_8068;
        obj->name = lbl_1_data_8578;
        obj->field8 = 0;
        obj->field24 = 0;
    }

    if (lbl_1_bss_1B5C == 0) {
        Pair temp;
        fn_80018280(&temp, 2);
        lbl_1_bss_1B5C = temp.first;
        lbl_1_bss_1B60 = temp.second;
        fn_1_33DBC(temp.first, temp.second);
    }

    return obj;
}
