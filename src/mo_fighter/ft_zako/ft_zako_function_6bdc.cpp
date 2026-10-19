#pragma force_active on
extern "C" {
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void* __register_global_object(void*, void*, void*);

struct Obj8 {
    char d[8];
};

extern char lbl_126_bss_74;
extern Obj8 lbl_126_bss_78;
extern char lbl_126_bss_60[];

void* fn_126_6BDC() {
    if (!lbl_126_bss_74) {
        fn_27_197E44(&lbl_126_bss_78);
        __register_global_object(&lbl_126_bss_78, (void*)fn_27_197E54, lbl_126_bss_60);
        lbl_126_bss_74 = 1;
    }
    return &lbl_126_bss_78;
}
}
