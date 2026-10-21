#pragma force_active on
extern "C" {
extern void* lbl_114_bss_354;
extern unsigned char lbl_114_bss_348[12];
void fn_114_163F8(void**);
void* fn_114_16370(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_114_163B0(void)
{
    fn_114_163F8(&lbl_114_bss_354);
    __register_global_object(&lbl_114_bss_354,
                             reinterpret_cast<void*>(fn_114_16370),
                             lbl_114_bss_348);
}

__declspec(section ".ctors") extern void* const fn_114_163B0_ctor = (void*)fn_114_163B0;
