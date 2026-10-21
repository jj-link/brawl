#pragma force_active on
extern "C" void fn_92_CFB0(void**);
extern "C" void fn_92_CF20(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_92_bss_1C4[];
extern "C" unsigned char lbl_92_bss_1B8[];

extern "C" void fn_92_CF68() {
    fn_92_CFB0(reinterpret_cast<void**>(lbl_92_bss_1C4));
    __register_global_object(
        lbl_92_bss_1C4,
        reinterpret_cast<void*>(fn_92_CF20),
        lbl_92_bss_1B8
    );
}

__declspec(section ".ctors") extern void* const fn_92_CF68_ctor = (void*)fn_92_CF68;
