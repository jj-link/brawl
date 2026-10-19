#pragma force_active on
struct FnObj {
    FnObj();
    ~FnObj();
};

extern "C" {
extern signed char lbl_125_bss_1BC;
extern FnObj lbl_125_bss_1C0;
extern char lbl_125_bss_1A4[];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
int __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" FnObj* fn_125_9E50() {
    if (!lbl_125_bss_1BC) {
        fn_27_197E44(&lbl_125_bss_1C0);
        __register_global_object(&lbl_125_bss_1C0, (void*)fn_27_197E54, lbl_125_bss_1A4);
        lbl_125_bss_1BC = 1;
    }
    return &lbl_125_bss_1C0;
}
