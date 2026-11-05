#pragma force_active on

struct Object {
    void* vtable;
};

extern "C" {
extern int lbl_27_data_2E980;
extern Object lbl_27_bss_48D4;
extern char lbl_27_bss_48C8[];
void fn_27_166BDC(void*, int);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_27_166C1C() {
    lbl_27_bss_48D4.vtable = 0;
    lbl_27_bss_48D4.vtable = &lbl_27_data_2E980;
    __register_global_object(&lbl_27_bss_48D4, (void*)fn_27_166BDC, lbl_27_bss_48C8);
}

__declspec(section ".ctors") extern void* const fn_27_166C1C_ctor = (void*)fn_27_166C1C;
