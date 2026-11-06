#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_7B3C;
extern char lbl_27_bss_7B30[0xC];
extern char lbl_27_data_83858[];
void fn_27_311CE8(void*, long);
void __register_global_object(void*, void*, void*);

void fn_27_311D28() {
    lbl_27_bss_7B3C.vtable = 0;
    lbl_27_bss_7B3C.vtable = (void*)&lbl_27_data_83858;
    __register_global_object(&lbl_27_bss_7B3C, (void*)fn_27_311CE8, lbl_27_bss_7B30);
}
}

__declspec(section ".ctors") extern void* const fn_27_311D28_ctor = (void*)fn_27_311D28;
