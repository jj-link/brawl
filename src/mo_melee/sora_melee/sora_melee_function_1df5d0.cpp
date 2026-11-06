#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_516C;
extern char lbl_27_data_45FE0[];
extern char lbl_27_bss_5160[];
void fn_27_1DF590(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DF5D0(void) {
    lbl_27_bss_516C.vtable = 0;
    lbl_27_bss_516C.vtable = (void*)&lbl_27_data_45FE0;
    __register_global_object(&lbl_27_bss_516C, (void*)fn_27_1DF590, lbl_27_bss_5160);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DF5D0_ctor = (void*)fn_27_1DF5D0;
