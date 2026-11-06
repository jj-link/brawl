#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern unsigned char lbl_27_data_92180[0x40];
extern GlobalObject lbl_27_bss_82D4;
extern unsigned char lbl_27_bss_82C8[0xC];
void fn_27_369A88(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_369AC8() {
    lbl_27_bss_82D4.vtable = 0;
    lbl_27_bss_82D4.vtable = (void*)lbl_27_data_92180;
    __register_global_object((void*)&lbl_27_bss_82D4, (void*)fn_27_369A88, (void*)lbl_27_bss_82C8);
}
}

__declspec(section ".ctors") extern void* const fn_27_369AC8_ctor = (void*)fn_27_369AC8;
