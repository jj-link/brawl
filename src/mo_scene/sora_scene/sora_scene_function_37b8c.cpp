#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8DA8[];
extern "C" unsigned char lbl_1_data_8ED0[];

struct SceneThing {
    void* vtable;
    void* name;
    int unk;
};

extern "C" SceneThing* fn_1_37B8C() {
    SceneThing* obj = (SceneThing*)__nw__FUlQ25Heaps8HeapType(0x14, 0x2e);
    if (obj != 0) {
        obj->vtable = lbl_1_data_8DA8;
        obj->name = lbl_1_data_8ED0;
        obj->unk = 0;
    }
    return obj;
}
