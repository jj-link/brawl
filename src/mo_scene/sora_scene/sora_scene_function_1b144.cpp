#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_1_13920(void* self, const char* name);
extern "C" void fn_1_139E0(void* self);
extern "C" char lbl_1_data_5C50[];
extern "C" char lbl_1_data_5C60[];

extern "C" {
void* fn_1_1B144() {
    unsigned char* obj = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x108, 0x2E);
    if (obj) {
        fn_1_13920(obj, lbl_1_data_5C50);
        *(char**)(obj + 0x4) = lbl_1_data_5C60;
        *(unsigned long*)(obj + 0x100) = 0;
        *(unsigned char*)(obj + 0x104) = 1;
        fn_1_139E0(obj);
    }
    return obj;
}
}
