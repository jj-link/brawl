#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtbl;
};
extern GlobalObject lbl_27_bss_4DCC;
extern char lbl_27_bss_4DC0[0xC];
extern char lbl_27_data_31390[0x40];
void* fn_27_188B68(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_188BA8() {
    lbl_27_bss_4DCC.vtbl = 0;
    lbl_27_bss_4DCC.vtbl = (void*)lbl_27_data_31390;
    __register_global_object((void*)&lbl_27_bss_4DCC, (void*)fn_27_188B68, (void*)lbl_27_bss_4DC0);
}
}

__declspec(section ".ctors") extern void* const fn_27_188BA8_ctor = (void*)fn_27_188BA8;
