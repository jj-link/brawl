#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_824C;
extern unsigned char lbl_27_data_90FF0[0x40];
extern unsigned char lbl_27_bss_8240[0xC];
void* fn_27_364098(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3640D8() {
    lbl_27_bss_824C.vtable = 0;
    lbl_27_bss_824C.vtable = lbl_27_data_90FF0;
    __register_global_object(&lbl_27_bss_824C, (void*)fn_27_364098, (void*)lbl_27_bss_8240);
}
}

__declspec(section ".ctors") extern void* const fn_27_3640D8_ctor = (void*)fn_27_3640D8;
