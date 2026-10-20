#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_7820[];
extern "C" unsigned char lbl_1_data_79C0[];
extern "C" void* lbl_1_bss_1A30;
extern "C" unsigned int lbl_1_bss_1A34;

struct Pair {
    void* first;
    unsigned int second;
};

struct Object {
    void* vtable;
    void* name;
    unsigned int field8;
    unsigned char rest[0x24];
};

extern "C" void fn_80018280(Pair*, int);
extern "C" void fn_1_290BC(void*, unsigned int);

extern "C" Object* fn_1_27898() {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x30, 0x2e);
    if (obj) {
        obj->vtable = lbl_1_data_7820;
        obj->name = lbl_1_data_79C0;
        obj->field8 = 0;
    }
    if (!lbl_1_bss_1A30) {
        Pair temp;
        fn_80018280(&temp, 0);
        lbl_1_bss_1A30 = temp.first;
        lbl_1_bss_1A34 = temp.second;
        fn_1_290BC(temp.first, temp.second);
    }
    return obj;
}
