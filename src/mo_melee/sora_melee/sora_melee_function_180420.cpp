#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4C1C;
extern char lbl_27_data_30740[0x40];
extern char lbl_27_bss_4C10[0xC];
void fn_27_1803E0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_180420() {
    lbl_27_bss_4C1C.vtable = 0;
    lbl_27_bss_4C1C.vtable = lbl_27_data_30740;
    __register_global_object((void*)&lbl_27_bss_4C1C, (void*)fn_27_1803E0, (void*)lbl_27_bss_4C10);
}
}

__declspec(section ".ctors") extern void* const fn_27_180420_ctor = (void*)fn_27_180420;
