#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_65_A4(void*);

void* fn_65_6AEC() {
    void* p = __nw__FUlQ25Heaps8HeapType(0xa64, 0xf);
    if (p != 0)
        return fn_65_A4(p);
    return p;
}
}
