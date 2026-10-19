#pragma force_active on
typedef struct Obj {
    int m_value;
} Obj;

extern "C" {
extern signed char lbl_115_bss_234;
extern Obj lbl_115_bss_238;
extern char lbl_115_bss_21C[12];
void fn_27_197E44(Obj* self);
void* fn_27_197E54(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" Obj* fn_115_8610() {
    if (lbl_115_bss_234 == 0) {
        fn_27_197E44(&lbl_115_bss_238);
        __register_global_object(&lbl_115_bss_238, (void*)fn_27_197E54, lbl_115_bss_21C);
        lbl_115_bss_234 = 1;
    }
    return &lbl_115_bss_238;
}
