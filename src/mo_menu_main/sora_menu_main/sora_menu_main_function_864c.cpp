#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_2_86B8(void*);
void fn_2_8C74(void*, void*, void*);
extern void* lbl_2_bss_38;

void* fn_2_864C(void* a, void* b) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x300, 2);
    if (p) {
        p = fn_2_86B8(p);
    }
    lbl_2_bss_38 = p;
    fn_2_8C74(p, a, b);
    return lbl_2_bss_38;
}
}
