#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned char lbl_1_data_7BA0[];
extern "C" unsigned char lbl_1_data_7E90[];

extern "C" void* fn_1_2ACAC() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x2C, 0x2E);
    if (p) {
        *(void**)((char*)p + 0x00) = lbl_1_data_7BA0;
        *(void**)((char*)p + 0x04) = lbl_1_data_7E90;
        *(unsigned int*)((char*)p + 0x08) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0;
        *(unsigned int*)((char*)p + 0x24) = 0;
        *(unsigned int*)((char*)p + 0x28) = 0;
    }
    return p;
}
