#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_41_2BEBC(void*);
extern "C" void fn_41_2CA7C();
extern void* lbl_41_bss_1C8;

extern "C" {
void fn_41_2BE64() {
    if (lbl_41_bss_1C8 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x298, 0x27);
        if (p != 0) {
            p = fn_41_2BEBC(p);
        }
        lbl_41_bss_1C8 = p;
        if (p != 0) {
            fn_41_2CA7C();
        }
    }
}
}
