#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};

extern char lbl_27_data_8BBA8[0x40];
extern char lbl_27_bss_7E08[0xC];
extern GlobalObject lbl_27_bss_7E14;

void* fn_27_33CD38(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_33CD78(void) {
    lbl_27_bss_7E14.vtable = 0;
    lbl_27_bss_7E14.vtable = (void*)&lbl_27_data_8BBA8;
    __register_global_object(&lbl_27_bss_7E14, (void*)fn_27_33CD38, (void*)lbl_27_bss_7E08);
}
}

__declspec(section ".ctors") extern void* const fn_27_33CD78_ctor = (void*)fn_27_33CD78;
