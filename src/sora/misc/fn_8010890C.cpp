#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80108950(void* obj, void* arg);

extern "C" void fn_8010890C(void* arg) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x44, 0x28);
    if (p != 0) {
        fn_80108950(p, arg);
    }
}
