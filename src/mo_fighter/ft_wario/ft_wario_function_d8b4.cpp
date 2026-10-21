#pragma force_active on
extern "C" void fn_110_D8FC(void*);
extern "C" void fn_110_D874(void*, short);
extern "C" void __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_110_bss_1A8[0xC];
extern "C" unsigned char lbl_110_bss_1B4[4];

extern "C" void fn_110_D8B4() {
    fn_110_D8FC(lbl_110_bss_1B4);
    __register_global_object(
        lbl_110_bss_1B4,
        (void*)fn_110_D874,
        lbl_110_bss_1A8
    );
}

__declspec(section ".ctors") extern void* const fn_110_D8B4_ctor = (void*)fn_110_D8B4;
