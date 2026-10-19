#pragma force_active on
extern "C" {
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, void*, void*);
extern unsigned char lbl_27_bss_298[];
}

extern "C" void* fn_100_72F0(void* self, void* arg, void* data) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C(static_cast<char*>(self) + 0x50, arg, self, data, lbl_27_bss_298);
    return self;
}
