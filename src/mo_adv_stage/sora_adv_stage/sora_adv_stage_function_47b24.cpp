#pragma force_active on

struct muAdvLoadTaskParam;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_40_432C0(void*, const muAdvLoadTaskParam*, int, int, int);
extern unsigned char lbl_40_data_18020[0x94];
}

extern "C" void* create__13muAdvLoadTaskFPC18muAdvLoadTaskParam(const muAdvLoadTaskParam* param) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x1898, 0x2a);
    if (p != 0) {
        fn_40_432C0(p, param, 0x2a, 0x2b, 0);
        *(void**)((char*)p + 0x3c) = lbl_40_data_18020;
    }
    return p;
}
