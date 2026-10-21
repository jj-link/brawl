#pragma force_active on
extern "C" {
extern signed char lbl_96_bss_BEC;
extern void* lbl_96_bss_BF0;
extern void* lbl_96_bss_BD4;
void fn_27_197C68(void**);
void* fn_27_82B94(void*, int);
void* __register_global_object(void*, void*, void*);
void fn_27_10158(void*, void*, int, void*, int);
}

extern "C" void* fn_96_9B24(char* obj, void* a, int b)
{
    if (!lbl_96_bss_BEC) {
        fn_27_197C68(&lbl_96_bss_BF0);
        __register_global_object(&lbl_96_bss_BF0, (void*)fn_27_82B94, &lbl_96_bss_BD4);
        lbl_96_bss_BEC = 1;
    }
    fn_27_10158(obj + 4, a, b, &lbl_96_bss_BF0, 1);
    return obj;
}
