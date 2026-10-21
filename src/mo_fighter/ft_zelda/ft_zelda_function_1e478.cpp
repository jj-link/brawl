#pragma force_active on
extern "C" {
void* __register_global_object(void* object, void* destructor, void* chain);
void* fn_104_1E438(void* p, short size);
void fn_104_1E4C0(void* p);
extern int lbl_104_bss_4F4;
extern char lbl_104_bss_4E8[12];
}

extern "C" void fn_104_1E478() {
    fn_104_1E4C0(&lbl_104_bss_4F4);
    __register_global_object(&lbl_104_bss_4F4, (void*)fn_104_1E438, lbl_104_bss_4E8);
}

__declspec(section ".ctors") extern void* const fn_104_1E478_ctor = (void*)fn_104_1E478;
