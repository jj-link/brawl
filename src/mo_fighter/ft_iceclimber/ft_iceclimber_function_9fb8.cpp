#pragma force_active on
typedef struct Obj {
    int m_value;
} Obj;

extern "C" {
extern signed char lbl_105_bss_258;
extern Obj lbl_105_bss_25C;
extern char lbl_105_bss_234[12];
void fn_27_197E44(Obj* self);
void* fn_27_197E54(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" Obj* fn_105_9FB8() {
    if (lbl_105_bss_258 == 0) {
        fn_27_197E44(&lbl_105_bss_25C);
        __register_global_object(&lbl_105_bss_25C, (void*)fn_27_197E54, lbl_105_bss_234);
        lbl_105_bss_258 = 1;
    }
    return &lbl_105_bss_25C;
}
