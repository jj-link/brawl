#pragma force_active on
extern "C" {
extern signed char lbl_126_bss_6C;
extern char lbl_126_bss_70[];
extern char lbl_126_bss_54[];
void fn_27_197BF8(void** p);
void fn_27_82C14(void);
void* __register_global_object(void* object, void* destructor, void* dso);
void* fn_27_14DFE4(void* p, unsigned int a2, unsigned char a3, void* a4, void* a5, void* a6, void* a7, unsigned int a8, int a9);
void fn_27_A78C0(void* self);
void fn_27_1991F0(void* self, int v);
void fn_27_19907C(void* self, int v);
}

extern "C" void* fn_126_6904(char* self, unsigned int a1, unsigned char a2, unsigned int a3) {
    if (lbl_126_bss_6C == 0) {
        fn_27_197BF8((void**)lbl_126_bss_70);
        __register_global_object(lbl_126_bss_70, (void*)fn_27_82C14, lbl_126_bss_54);
        lbl_126_bss_6C = 1;
    }
    fn_27_14DFE4(self + 4, a1, a2, self + 0x214, self + 0x88, self + 0x6C, lbl_126_bss_70, a3, -1);
    fn_27_A78C0(self + 0x6C);
    fn_27_1991F0(self + 0x88, 0);
    fn_27_19907C(self + 0x214, 0);
    return self;
}
