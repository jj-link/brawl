#pragma force_active on
extern "C" {
extern signed char lbl_102_bss_4CC;
extern void* lbl_102_bss_4D0;
extern void* lbl_102_bss_4B4;
void fn_27_197BF8(void** p);
void* fn_27_82C14(void* ptr, int size);
void* __register_global_object(void* object, void* destructor, void* dso);
void fn_27_A34D4(void* a1, void* a2, unsigned char a3, void* a4, void* a5, void* a6, void* a7, void* a8, int a9);
void fn_27_A78C0(void* self);
void fn_27_1992F4(void* w, int x);
void fn_27_198D94(void* self, int x);
}

extern "C" void* fn_102_12B84(char* self, void* b, unsigned char c, void* d) {
    if (lbl_102_bss_4CC == 0) {
        fn_27_197BF8(&lbl_102_bss_4D0);
        __register_global_object(&lbl_102_bss_4D0, (void*)fn_27_82C14, &lbl_102_bss_4B4);
        lbl_102_bss_4CC = 1;
    }
    fn_27_A34D4(self + 4, b, c, self + 0xD8, self + 0x6C, self + 0x50, &lbl_102_bss_4D0, d, -1);
    fn_27_A78C0(self + 0x50);
    fn_27_1992F4(self + 0x6C, 0);
    fn_27_198D94(self + 0xD8, 0);
    return self;
}
