#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_110_D074(void*);
extern "C" void* fn_110_CFE8(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" u32 lbl_110_bss_194;
extern "C" u32 lbl_110_bss_188[];

extern "C" void fn_110_D02C() {
    fn_110_D074(&lbl_110_bss_194);
    __register_global_object(
        &lbl_110_bss_194,
        (void*)fn_110_CFE8,
        (void*)lbl_110_bss_188);
}

__declspec(section ".ctors") extern void* const fn_110_D02C_ctor = (void*)fn_110_D02C;
