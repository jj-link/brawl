#pragma force_active on

extern "C" {
extern char lbl_27_data_2E9F0[];
extern char lbl_27_bss_48D8[12];
void fn_27_167058(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_48E4;

extern "C" void fn_27_167098(void) {
    lbl_27_bss_48E4.vtable = 0;
    lbl_27_bss_48E4.vtable = (void*)&lbl_27_data_2E9F0;
    __register_global_object(&lbl_27_bss_48E4, (void*)fn_27_167058, lbl_27_bss_48D8);
}

__declspec(section ".ctors") extern void* const fn_27_167098_ctor = (void*)fn_27_167098;
