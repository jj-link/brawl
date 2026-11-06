#pragma force_active on

extern "C" {
extern char lbl_27_data_90610[];
void fn_27_360844(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_81F4;

extern "C" {
extern char lbl_27_bss_81E8[0xC];

void fn_27_360884() {
    lbl_27_bss_81F4.vtable = 0;
    lbl_27_bss_81F4.vtable = (void*)&lbl_27_data_90610;
    __register_global_object(&lbl_27_bss_81F4, (void*)fn_27_360844, (void*)lbl_27_bss_81E8);
}
}

__declspec(section ".ctors") extern void* const fn_27_360884_ctor = (void*)fn_27_360884;
