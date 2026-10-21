#pragma force_active on
extern "C" void fn_110_1A078(void*);
extern "C" void* fn_110_19FF0(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_110_bss_3D4[];
extern "C" unsigned char lbl_110_bss_3C8[];

extern "C" void fn_110_1A030() {
    fn_110_1A078(lbl_110_bss_3D4);
    __register_global_object(
        lbl_110_bss_3D4,
        (void*)fn_110_19FF0,
        lbl_110_bss_3C8
    );
}

__declspec(section ".ctors") extern void* const fn_110_1A030_ctor = (void*)fn_110_1A030;
