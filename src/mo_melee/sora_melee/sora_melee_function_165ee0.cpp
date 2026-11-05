#pragma force_active on
struct GlobalObject {
    void* vtable;
};
extern "C" {
extern char lbl_27_data_2E830[0x40];
extern char lbl_27_bss_4898[0xC];
extern GlobalObject lbl_27_bss_48A4;
void* fn_27_165EA0(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_165EE0() {
    lbl_27_bss_48A4.vtable = 0;
    lbl_27_bss_48A4.vtable = (void*)lbl_27_data_2E830;
    __register_global_object((void*)&lbl_27_bss_48A4, (void*)fn_27_165EA0, (void*)lbl_27_bss_4898);
}
}

__declspec(section ".ctors") extern void* const fn_27_165EE0_ctor = (void*)fn_27_165EE0;
