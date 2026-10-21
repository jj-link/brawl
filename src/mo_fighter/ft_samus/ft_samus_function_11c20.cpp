#pragma force_active on
extern "C" void fn_94_11C68(void*);
extern "C" void* fn_94_11BE0(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_94_bss_20C[];
extern "C" unsigned char lbl_94_bss_200[];

extern "C" void fn_94_11C20(void) {
    fn_94_11C68(lbl_94_bss_20C);
    __register_global_object(
        lbl_94_bss_20C,
        reinterpret_cast<void*>(fn_94_11BE0),
        lbl_94_bss_200
    );
}

__declspec(section ".ctors") extern void* const fn_94_11C20_ctor = (void*)fn_94_11C20;
