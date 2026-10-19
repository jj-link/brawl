#pragma force_active on
typedef signed char s8;
typedef int s32;

extern "C" {
extern s8 lbl_96_bss_1000;
extern s32 lbl_96_bss_1004;
extern char lbl_96_bss_E8C[];
void fn_27_345BAC(void* p);
void* fn_27_345BBC(void* p, s32 flags);
void __register_global_object(void* object, void* destructor, void* chain);

void* fn_96_1FF7C() {
    if (!lbl_96_bss_1000) {
        fn_27_345BAC(&lbl_96_bss_1004);
        __register_global_object(&lbl_96_bss_1004, (void*)fn_27_345BBC, lbl_96_bss_E8C);
        lbl_96_bss_1000 = 1;
    }
    return &lbl_96_bss_1004;
}
}
