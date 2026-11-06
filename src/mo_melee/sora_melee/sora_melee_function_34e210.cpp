#pragma force_active on

extern "C" {
extern char lbl_27_data_8D850[];
void* fn_27_34E1D0(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_34E210(void);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7F44;
extern char lbl_27_bss_7F38[0xC];

extern "C" void fn_27_34E210(void) {
    lbl_27_bss_7F44.vtable = 0;
    lbl_27_bss_7F44.vtable = (void*)&lbl_27_data_8D850;
    __register_global_object(&lbl_27_bss_7F44, (void*)fn_27_34E1D0, lbl_27_bss_7F38);
}

__declspec(section ".ctors") extern void* const fn_27_34E210_ctor = (void*)fn_27_34E210;
