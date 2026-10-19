#pragma force_active on
extern "C" {
void fn_27_12DCA8(void);
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_368B30(void*);
}

extern "C" void fn_116_1F7D8(void* self) {
    fn_27_12DCA8();
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        fn_27_368B30(static_cast<unsigned char*>(self) + 0x11118);
    }
}
