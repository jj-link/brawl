#pragma force_active on

extern "C" {
extern char lbl_27_data_2E748[];
extern char lbl_27_bss_4878[12];
void fn_27_1658B0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4884;

extern "C" void fn_27_1658F0(void) {
    lbl_27_bss_4884.vtable = 0;
    lbl_27_bss_4884.vtable = (void*)&lbl_27_data_2E748;
    __register_global_object(&lbl_27_bss_4884, (void*)fn_27_1658B0, lbl_27_bss_4878);
}

__declspec(section ".ctors") extern void* const fn_27_1658F0_ctor = (void*)fn_27_1658F0;
