#pragma force_active on

extern "C" {
extern char lbl_27_data_98FE8[];
extern char lbl_27_bss_87E0[12];
void* fn_27_3868E4(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_87EC;

extern "C" void fn_27_386924(void) {
    lbl_27_bss_87EC.vtable = 0;
    lbl_27_bss_87EC.vtable = (void*)&lbl_27_data_98FE8;
    __register_global_object(&lbl_27_bss_87EC, (void*)fn_27_3868E4, (void*)lbl_27_bss_87E0);
}

__declspec(section ".ctors") extern void* const fn_27_386924_ctor = (void*)fn_27_386924;
