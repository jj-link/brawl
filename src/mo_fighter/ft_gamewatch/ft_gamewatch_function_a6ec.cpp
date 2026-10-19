#pragma force_active on
extern "C" {
extern signed char lbl_107_bss_13C;
extern char lbl_107_bss_140[4];
extern char lbl_107_bss_124[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_107_A6EC() {
    if (lbl_107_bss_13C == 0) {
        fn_27_197E44(lbl_107_bss_140);
        __register_global_object(lbl_107_bss_140, (void*)fn_27_197E54, lbl_107_bss_124);
        lbl_107_bss_13C = 1;
    }
    return lbl_107_bss_140;
}
}
