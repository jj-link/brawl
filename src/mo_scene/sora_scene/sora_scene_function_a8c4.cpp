#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" unsigned int lbl_1_data_39B0[];
extern "C" unsigned int lbl_1_data_3A38[];

struct TwoPtr {
    void* mFirst;
    void* mSecond;
};

extern "C" TwoPtr* fn_1_A8C4() {
    TwoPtr* p = (TwoPtr*)__nw__FUlQ25Heaps8HeapType(0xc, 0x2e);
    if (p != 0) {
        p->mFirst = (void*)&lbl_1_data_39B0;
        p->mSecond = (void*)&lbl_1_data_3A38;
    }
    return p;
}
