#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_70_A4(void*);

extern "C" void fn_70_70() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x298, 0x0F);
    if (obj != 0) {
        fn_70_A4(obj);
    }
}
