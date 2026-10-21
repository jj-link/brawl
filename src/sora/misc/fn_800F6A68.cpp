#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_800F6788(void* obj, void* arg);

extern "C" void fn_800F6A68(void* arg) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x430, 0xF);
    if (p != 0) {
        fn_800F6788(p, arg);
    }
}
