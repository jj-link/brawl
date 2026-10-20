#pragma force_active on
struct muAdvSaveTaskParam;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_40_432C0(void*, const muAdvSaveTaskParam*, int, int, int);
extern unsigned char lbl_40_data_180F0[0x94];
}

extern "C" void* create__13muAdvSaveTaskFPC18muAdvSaveTaskParamQ25Heaps8HeapTypeUl(const muAdvSaveTaskParam* param, int heapType, unsigned long p3) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1898, heapType);
    if (p != 0) {
        fn_40_432C0(p, param, heapType, p3, 1);
        *(void**)((char*)p + 0x3c) = lbl_40_data_180F0;
        *(unsigned char*)((char*)p + 0x1422) = 1;
    }
    return p;
}
