#pragma force_active on
extern "C" {
extern void* lbl_27_bss_F0;
extern void fn_27_12DCA8(void*);
extern void* fn_116_972C();
extern void fn_27_368DAC(void*, void*);
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern void* fn_27_5BCD0(void*);
extern unsigned int fn_27_5BE80(void*);
extern void fn_27_368B30(void*);

void fn_116_9850(void* self) {
    fn_27_12DCA8(self);
    void* ptr = fn_116_972C();
    fn_27_368DAC(ptr, *(void**)((char*)self + 0x60));
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        fn_27_368B30((char*)self + 0x17FA4);
    }
}
}
