#pragma force_active on
extern "C" void fn_113_25D30(void*);
extern "C" void fn_113_25CA8(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);
extern "C" unsigned char lbl_113_bss_204[4];
extern "C" unsigned char lbl_113_bss_1F8[12];

extern "C" void fn_113_25CE8(void) {
    fn_113_25D30(lbl_113_bss_204);
    __register_global_object(lbl_113_bss_204, (void*)fn_113_25CA8, lbl_113_bss_1F8);
}

__declspec(section ".ctors") extern void* const fn_113_25CE8_ctor = (void*)fn_113_25CE8;
