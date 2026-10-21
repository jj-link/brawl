#pragma force_active on
extern "C" {
extern unsigned char lbl_41_bss_94[0xC];
extern unsigned char lbl_41_bss_88[0xC];
void fn_41_1F838(void*);
void* fn_41_1F890(void*, short);
void __register_global_object(void*, void*, void*);

void fn_41_213DC() {
    fn_41_1F838(lbl_41_bss_94);
    __register_global_object(lbl_41_bss_94, (void*)fn_41_1F890, lbl_41_bss_88);
}
}

__declspec(section ".ctors") extern void* const fn_41_213DC_ctor = (void*)fn_41_213DC;
