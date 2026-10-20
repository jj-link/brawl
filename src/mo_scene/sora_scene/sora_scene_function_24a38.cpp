#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_7510[];
extern "C" unsigned char lbl_1_data_77A8[];
extern "C" u8* lbl_1_bss_198C;
extern "C" u32 lbl_1_bss_1990;

struct Pair {
    u8* data;
    u32 size;
};

extern "C" void fn_80018280(Pair*, int);
extern "C" void fn_1_271A8(u8*, u32);

struct Object {
    void* vtable;
    void* name;
    u32 field8;
    u32 fieldC;
    u32 field10;
    u32 field14;
    u32 field18;
    u8 rest[0x1C];
};

extern "C" Object* fn_1_24A38() {
    Object* obj = (Object*)__nw__FUlQ25Heaps8HeapType(0x38, 0x2E);
    if (obj) {
        obj->vtable = lbl_1_data_7510;
        obj->name = lbl_1_data_77A8;
        obj->field8 = 0;
        obj->field14 = 0;
        obj->field18 = 0;
    }

    if (!lbl_1_bss_198C) {
        Pair temp;
        fn_80018280(&temp, 1);
        lbl_1_bss_198C = temp.data;
        lbl_1_bss_1990 = temp.size;
        fn_1_271A8(temp.data, temp.size);
    }

    return obj;
}
