#pragma force_active on
typedef struct Obj {
    int m_value;
} Obj;

extern "C" {
extern signed char lbl_116_bss_14C;
extern Obj lbl_116_bss_150;
extern char lbl_116_bss_134[12];
void fn_27_197E44(Obj* self);
void* fn_27_197E54(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" Obj* fn_116_9178() {
    if (lbl_116_bss_14C == 0) {
        fn_27_197E44(&lbl_116_bss_150);
        __register_global_object(&lbl_116_bss_150, (void*)fn_27_197E54, lbl_116_bss_134);
        lbl_116_bss_14C = 1;
    }
    return &lbl_116_bss_150;
}
