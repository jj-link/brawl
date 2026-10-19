#pragma force_active on
extern "C" void fn_27_CC060(void*, int, int);
extern "C" void fn_27_2556C(void*, void*, void*, void*, void*);
extern "C" unsigned char lbl_27_bss_298[];

extern "C" void* fn_111_65C8(void* self, void* arg, void* data) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C(static_cast<unsigned char*>(self) + 0x50, arg, self, data, lbl_27_bss_298);
    return self;
}
