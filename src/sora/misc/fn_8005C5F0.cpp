#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8005AD3C(void*);
extern void* lbl_805A0110;

extern "C" void fn_8005C5F0() {
    if (lbl_805A0110 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x13C, 2);
        if (p != 0) {
            p = fn_8005AD3C(p);
        }
        lbl_805A0110 = p;
    }
}
