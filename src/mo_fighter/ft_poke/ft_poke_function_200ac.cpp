#pragma force_active on
extern "C" {
extern signed char lbl_116_bss_5A4;
extern void* lbl_116_bss_5A8;
extern char lbl_116_bss_590[0x14];

void fn_27_36DF54(void* ptr);
void fn_27_36DF64(void* ptr, int release);
void* __register_global_object(void* object, void* destructor, void* chain);
int fn_27_36E158(void* a, void* b, void* c, int d);
}

extern "C" int fn_116_200AC(void* a, void* b) {
    if (lbl_116_bss_5A4 == 0) {
        fn_27_36DF54(&lbl_116_bss_5A8);
        __register_global_object(&lbl_116_bss_5A8, (void*)fn_27_36DF64, lbl_116_bss_590);
        lbl_116_bss_5A4 = 1;
    }
    return fn_27_36E158(&lbl_116_bss_5A8, a, b, 0);
}
