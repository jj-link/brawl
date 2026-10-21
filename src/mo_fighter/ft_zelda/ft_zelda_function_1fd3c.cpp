#pragma force_active on

extern "C" void fn_104_1FD84(void*);
extern "C" void* fn_104_1FCFC(void*, short);
extern "C" void* __register_global_object(void*, void*, void*);

extern "C" unsigned char lbl_104_bss_534[4];
extern "C" unsigned char lbl_104_bss_528[12];

extern "C" void fn_104_1FD3C(void) {
    fn_104_1FD84(lbl_104_bss_534);
    __register_global_object(lbl_104_bss_534, (void*)fn_104_1FCFC, lbl_104_bss_528);
}

__declspec(section ".ctors") extern void* const fn_104_1FD3C_ctor = (void*)fn_104_1FD3C;
