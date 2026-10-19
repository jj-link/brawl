#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

extern "C" u8 lbl_111_bss_170;
extern "C" u8 lbl_111_bss_174;
extern "C" u8 lbl_111_bss_164;

extern "C" void fn_27_197E44(void*);
extern "C" void fn_27_197E54(void*, int);
extern "C" void __register_global_object(void*, void*, void*);

extern "C" void* fn_111_7AA4(void) {
    if ((s8)lbl_111_bss_170 == 0) {
        fn_27_197E44(&lbl_111_bss_174);
        __register_global_object(&lbl_111_bss_174,
                                 (void*)fn_27_197E54,
                                 &lbl_111_bss_164);
        lbl_111_bss_170 = 1;
    }
    return &lbl_111_bss_174;
}
