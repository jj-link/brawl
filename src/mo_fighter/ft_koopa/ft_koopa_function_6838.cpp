#pragma force_active on
extern "C" void fn_27_CC060(void*, int, int);
extern "C" void fn_27_2556C(void*, void*, void*, void*, void*);
extern "C" unsigned char lbl_27_bss_298[];

extern "C" void* fn_102_6838(void* self, void* accesser, void* groundData) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C((char*)self + 0x50, accesser, self, groundData, lbl_27_bss_298);
    return self;
}
