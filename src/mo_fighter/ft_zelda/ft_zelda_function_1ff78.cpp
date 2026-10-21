#pragma force_active on
extern "C" void fn_104_1FF78() {
    extern unsigned char lbl_104_bss_544[];
    extern unsigned char lbl_104_bss_538[];
    extern void fn_104_1FFC0(void*);
    extern void* fn_104_1FF38(void*, short);
    extern void* __register_global_object(void*, void*, void*);

    fn_104_1FFC0(lbl_104_bss_544);
    __register_global_object(lbl_104_bss_544, (void*)fn_104_1FF38,
                             lbl_104_bss_538);
}

__declspec(section ".ctors") extern void* const fn_104_1FF78_ctor = (void*)fn_104_1FF78;
