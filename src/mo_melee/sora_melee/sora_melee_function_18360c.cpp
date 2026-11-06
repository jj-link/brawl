#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern char lbl_27_data_309B0[];
extern char lbl_27_bss_4C60[12];
extern GlobalObject lbl_27_bss_4C6C;
void fn_27_1835CC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_18360C(void) {
    lbl_27_bss_4C6C.vtable = 0;
    lbl_27_bss_4C6C.vtable = (void*)&lbl_27_data_309B0;
    __register_global_object(&lbl_27_bss_4C6C, (void*)fn_27_1835CC, lbl_27_bss_4C60);
}
}

__declspec(section ".ctors") extern void* const fn_27_18360C_ctor = (void*)fn_27_18360C;
