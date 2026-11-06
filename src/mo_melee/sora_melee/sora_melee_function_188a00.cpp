#pragma force_active on

extern "C" {
extern char lbl_27_data_31320[];
extern char lbl_27_bss_4DB0[12];
void* fn_27_1889C0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4DBC;

extern "C" void fn_27_188A00(void) {
    lbl_27_bss_4DBC.vtable = 0;
    lbl_27_bss_4DBC.vtable = (void*)&lbl_27_data_31320;
    __register_global_object(&lbl_27_bss_4DBC, (void*)fn_27_1889C0, lbl_27_bss_4DB0);
}

__declspec(section ".ctors") extern void* const fn_27_188A00_ctor = (void*)fn_27_188A00;
