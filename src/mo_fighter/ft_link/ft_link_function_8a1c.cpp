#pragma force_active on
extern "C" {
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);
extern signed char lbl_93_bss_12C;
extern int lbl_93_bss_130;
extern int lbl_93_bss_114[3];
}

extern "C" void* fn_93_8A1C()
{
    if (lbl_93_bss_12C == 0) {
        fn_27_197E44(&lbl_93_bss_130);
        __register_global_object(&lbl_93_bss_130, (void*)fn_27_197E54, lbl_93_bss_114);
        lbl_93_bss_12C = 1;
    }
    return &lbl_93_bss_130;
}
