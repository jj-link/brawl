#pragma force_active on
extern "C" {
void fn_104_24BAC(void* p);
void* fn_104_24B24(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_104_bss_638[3];
extern void* lbl_104_bss_644;
}

extern "C" void fn_104_24B64() {
    fn_104_24BAC(&lbl_104_bss_644);
    __register_global_object(&lbl_104_bss_644, (void*)fn_104_24B24, lbl_104_bss_638);
}

__declspec(section ".ctors") extern void* const fn_104_24B64_ctor = (void*)fn_104_24B64;
