#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800AD808(void*, int);

extern "C" void fn_8015B1E0(void* arg) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x3EB4, 0x2A);
    if (p) {
        p = fn_800AD808(p, 1);
    }
    *(void**)arg = p;
}
