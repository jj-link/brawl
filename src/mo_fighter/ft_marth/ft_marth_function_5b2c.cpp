#pragma force_active on
extern "C" {
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, void*, void*);
extern unsigned char lbl_27_bss_298[];
}

extern "C" void* fn_106_5B2C(void* self, void* arg, void* data) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C((unsigned char*)self + 0x50, arg, self, data, lbl_27_bss_298);
    return self;
}
