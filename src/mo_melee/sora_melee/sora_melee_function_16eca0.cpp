#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern GlobalObject lbl_27_bss_4A7C;
extern char lbl_27_data_2F578[];
extern char lbl_27_bss_4A70[];
void fn_27_16EC60(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_16ECA0() {
    lbl_27_bss_4A7C.vtable = 0;
    lbl_27_bss_4A7C.vtable = &lbl_27_data_2F578;
    __register_global_object((void*)&lbl_27_bss_4A7C, (void*)fn_27_16EC60, (void*)lbl_27_bss_4A70);
}

__declspec(section ".ctors") extern void* const fn_27_16ECA0_ctor = (void*)fn_27_16ECA0;
