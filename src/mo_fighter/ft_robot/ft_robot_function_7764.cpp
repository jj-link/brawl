#pragma force_active on
typedef signed char s8;

extern "C" {
void fn_27_197C68(void*);
void fn_27_82B94(void*, short);
void* __register_global_object(void*, void*, void*);
void fn_27_10158(void*, void*, int, void*, int);

extern unsigned char lbl_120_bss_290;
extern unsigned char lbl_120_bss_294;
extern unsigned char lbl_120_bss_26C[];
}

extern "C" void* fn_120_7764(void* object, void* arg, int value)
{
    if ((s8)lbl_120_bss_290 == 0) {
        fn_27_197C68(&lbl_120_bss_294);
        __register_global_object(&lbl_120_bss_294,
                                 (void*)fn_27_82B94,
                                 lbl_120_bss_26C);
        lbl_120_bss_290 = 1;
    }

    fn_27_10158((char*)object + 4, arg, value, &lbl_120_bss_294, 1);
    return object;
}
