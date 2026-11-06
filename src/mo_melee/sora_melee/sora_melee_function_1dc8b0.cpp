#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_509C;
extern char lbl_27_data_45948[];
extern char lbl_27_bss_5090[12];
void fn_27_1DC808(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DC8B0() {
    lbl_27_bss_509C.vtable = 0;
    lbl_27_bss_509C.vtable = (void*)lbl_27_data_45948;
    __register_global_object(&lbl_27_bss_509C, (void*)fn_27_1DC808, lbl_27_bss_5090);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DC8B0_ctor = (void*)fn_27_1DC8B0;
