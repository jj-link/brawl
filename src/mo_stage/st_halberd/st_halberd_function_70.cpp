#pragma force_active on
#pragma opt_propagation off

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_57_A4(void*);

void fn_57_70() {
    void* p = __nw__FUlQ25Heaps8HeapType(0x9CC, 0xF);
    if (p != 0) {
        fn_57_A4(p);
    }
}
}
