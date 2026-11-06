#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern unsigned char lbl_27_data_88A80[0x40];
extern GlobalObject lbl_27_bss_7D74;
extern unsigned char lbl_27_bss_7D68[0xC];
void* fn_27_32F068(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_32F0A8() {
    lbl_27_bss_7D74.vtable = 0;
    lbl_27_bss_7D74.vtable = (void*)&lbl_27_data_88A80;
    __register_global_object(&lbl_27_bss_7D74, (void*)fn_27_32F068, lbl_27_bss_7D68);
}
}

__declspec(section ".ctors") extern void* const fn_27_32F0A8_ctor = (void*)fn_27_32F0A8;
