#pragma force_active on
struct GlobalObject {
    void* vtable;
};
extern "C" {
extern char lbl_27_data_2F698[0x44];
extern GlobalObject lbl_27_bss_4A9C;
extern char lbl_27_bss_4A90[0xC];
void* fn_27_170744(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_170784() {
    lbl_27_bss_4A9C.vtable = 0;
    lbl_27_bss_4A9C.vtable = (void*)lbl_27_data_2F698;
    __register_global_object((void*)&lbl_27_bss_4A9C, (void*)fn_27_170744, (void*)lbl_27_bss_4A90);
}
}

__declspec(section ".ctors") extern void* const fn_27_170784_ctor = (void*)fn_27_170784;
