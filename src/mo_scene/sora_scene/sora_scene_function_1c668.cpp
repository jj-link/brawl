#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_5F50[];
extern "C" char lbl_1_data_6010[];

extern "C" void* fn_1_1C668() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x20, 0x2e);
    if (p) {
        *(void**)p = lbl_1_data_5F50;
        *(void**)((char*)p + 4) = lbl_1_data_6010;
        *(unsigned int*)((char*)p + 0x14) = 0;
        *(unsigned int*)((char*)p + 0x18) = 0;
        *(unsigned int*)((char*)p + 8) = 0;
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
    }
    return p;
}
