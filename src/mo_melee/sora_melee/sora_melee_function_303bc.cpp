#pragma force_active on

extern "C" {
extern char lbl_27_data_2E90[];
extern char lbl_27_bss_30[0xC];
void fn_27_3037C(void*, int);
void* __register_global_object(void* object, void* dtor, void* chain);
}

struct State {
    void* vtable;
};

extern State lbl_27_bss_3C;

extern "C" void fn_27_303BC() {
    lbl_27_bss_3C.vtable = 0;
    lbl_27_bss_3C.vtable = lbl_27_data_2E90;
    __register_global_object(&lbl_27_bss_3C, (void*)fn_27_3037C, lbl_27_bss_30);
}

__declspec(section ".ctors") extern void* const fn_27_303BC_ctor = (void*)fn_27_303BC;
