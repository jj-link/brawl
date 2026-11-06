#pragma force_active on

extern "C" {
extern char lbl_27_data_8B7C8[];
extern char lbl_27_bss_7DF8[0xC];
void fn_27_33C4AC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7E04;

extern "C" void fn_27_33C4EC(void) {
    lbl_27_bss_7E04.vtable = 0;
    lbl_27_bss_7E04.vtable = (void*)&lbl_27_data_8B7C8;
    __register_global_object(&lbl_27_bss_7E04, (void*)fn_27_33C4AC, lbl_27_bss_7DF8);
}

__declspec(section ".ctors") extern void* const fn_27_33C4EC_ctor = (void*)fn_27_33C4EC;
