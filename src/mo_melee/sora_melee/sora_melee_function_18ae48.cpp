#pragma force_active on
extern "C" {
extern char lbl_27_data_31748[];
extern char lbl_27_bss_4E30[];
extern void fn_27_18AE08(void*, int);
extern void __register_global_object(void*, void*, void*);

struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4E3C;

void fn_27_18AE48() {
    lbl_27_bss_4E3C.vtable = 0;
    lbl_27_bss_4E3C.vtable = (void*)&lbl_27_data_31748;
    __register_global_object(&lbl_27_bss_4E3C, (void*)fn_27_18AE08, (void*)lbl_27_bss_4E30);
}
}

__declspec(section ".ctors") extern void* const fn_27_18AE48_ctor = (void*)fn_27_18AE48;
