#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_7C148[];
extern char lbl_27_bss_73B0[0xC];
extern GlobalObject lbl_27_bss_73BC;
void* fn_27_2DE6F0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_2DE730() {
    lbl_27_bss_73BC.vtable = 0;
    lbl_27_bss_73BC.vtable = lbl_27_data_7C148;
    __register_global_object(&lbl_27_bss_73BC, fn_27_2DE6F0, lbl_27_bss_73B0);
}
}

__declspec(section ".ctors") extern void* const fn_27_2DE730_ctor = (void*)fn_27_2DE730;
