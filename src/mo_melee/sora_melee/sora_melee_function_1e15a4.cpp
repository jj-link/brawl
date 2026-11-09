#pragma force_active on

extern "C" {
void __register_global_object(void*, void*, void*);
void fn_27_687F8(void*, void*, void*, void*);
void fn_27_82B14(void*, short);

extern char lbl_27_data_12858[];
extern char lbl_27_bss_51C4[];
extern signed char lbl_27_bss_5218;
}

struct GlobalObject { void* vtable; };
extern GlobalObject lbl_27_bss_521C;

static inline GlobalObject* getGlobal() {
    if (lbl_27_bss_5218 == 0) {
        lbl_27_bss_521C.vtable = 0;
        lbl_27_bss_521C.vtable = &lbl_27_data_12858;
        __register_global_object(&lbl_27_bss_521C, (void*)fn_27_82B14, lbl_27_bss_51C4);
        lbl_27_bss_5218 = 1;
    }
    return &lbl_27_bss_521C;
}

extern "C" void* fn_27_1E15A4(void* a, void* b, void* c) {
    fn_27_687F8((char*)a + 4, b, getGlobal(), c);
    return a;
}
