#pragma force_active on
extern "C" void fn_27_CC060(void*, int, int);
extern "C" void fn_27_2556C(void*, void*, void*, int, void*);
extern "C" unsigned char lbl_27_bss_298[];

extern "C" void* fn_99_6808(void* a, void* b, int c) {
    fn_27_CC060(a, 1, 0);
    fn_27_2556C(static_cast<unsigned char*>(a) + 0x50, b, a, c, lbl_27_bss_298);
    return a;
}
