#pragma force_active on
extern "C" {
void fn_107_12608(void** ptr);
void* fn_107_12580(void* slot, short destroy);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_107_bss_18C;
extern unsigned char lbl_107_bss_180[12];
}

extern "C" void fn_107_125C0(void)
{
    fn_107_12608(&lbl_107_bss_18C);
    __register_global_object(&lbl_107_bss_18C, (void*)fn_107_12580, lbl_107_bss_180);
}

__declspec(section ".ctors") extern void* const fn_107_125C0_ctor = (void*)fn_107_125C0;
