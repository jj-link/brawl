#pragma force_active on
extern "C" void* lbl_27_bss_5780;
extern "C" void* fn_27_22A914(void*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_27_22B504(void*, void*, void*, int*);

extern "C" void fn_27_154BDC(void* unused, void* a, void* b, void* c) {
    int info;
    void* obj = *(void**)((char*)a + 8);
    info = *(int*)((char*)obj + 0x28);
    unsigned int v = *(unsigned int*)((char*)*(void**)((char*)a + 8) + 0x2c);
    info = (int)(((v << 17) | (v >> 15)) & 0xFF800000) >> 24;
    if (lbl_27_bss_5780 == 0) {
        void* m = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (m != 0) {
            m = fn_27_22A914(m);
        }
        lbl_27_bss_5780 = m;
    }
    fn_27_22B504(lbl_27_bss_5780, *(void**)((char*)b + 4), *(void**)((char*)c + 4), &info);
}
