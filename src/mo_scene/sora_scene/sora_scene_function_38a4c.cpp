#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_8F38[];
extern "C" unsigned char lbl_1_data_9004[];

struct fn_1_38A4C_object {
    const unsigned char* vtable;
    const unsigned char* data;
    unsigned int unk8;
};

extern "C" fn_1_38A4C_object* fn_1_38A4C() {
    fn_1_38A4C_object* obj =
        (fn_1_38A4C_object*)__nw__FUlQ25Heaps8HeapType(0x14, 0x2e);
    if (obj != 0) {
        obj->vtable = lbl_1_data_8F38;
        obj->data = lbl_1_data_9004;
        obj->unk8 = 0;
    }
    return obj;
}
