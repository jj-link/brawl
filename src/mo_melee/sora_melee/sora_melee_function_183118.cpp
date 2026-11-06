#pragma force_active on

extern "C" {
extern char lbl_27_data_30938[];
extern char lbl_27_bss_4C50[12];
void fn_27_1830D8(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4C5C;

extern "C" void fn_27_183118(void) {
    lbl_27_bss_4C5C.vtable = 0;
    lbl_27_bss_4C5C.vtable = (void*)&lbl_27_data_30938;
    __register_global_object(&lbl_27_bss_4C5C, (void*)fn_27_1830D8, lbl_27_bss_4C50);
}

__declspec(section ".ctors") extern void* const fn_27_183118_ctor = (void*)fn_27_183118;
