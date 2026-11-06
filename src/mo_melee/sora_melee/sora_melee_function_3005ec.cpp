#pragma force_active on

extern "C" {
extern char lbl_27_data_816A0[];
extern char lbl_27_bss_7650[12];
void fn_27_3005AC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_765C;

extern "C" void fn_27_3005EC(void) {
    lbl_27_bss_765C.vtable = 0;
    lbl_27_bss_765C.vtable = (void*)&lbl_27_data_816A0;
    __register_global_object(&lbl_27_bss_765C, (void*)fn_27_3005AC, lbl_27_bss_7650);
}

__declspec(section ".ctors") extern void* const fn_27_3005EC_ctor = (void*)fn_27_3005EC;
