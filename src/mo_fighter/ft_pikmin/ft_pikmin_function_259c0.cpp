#pragma force_active on
extern "C" {
void fn_113_25A08(void* self);
void* fn_113_25980(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern unsigned char lbl_113_bss_1F4[4];
extern unsigned char lbl_113_bss_1E8[12];
}

extern "C" void fn_113_259C0()
{
    fn_113_25A08(lbl_113_bss_1F4);
    __register_global_object(lbl_113_bss_1F4, (void*)fn_113_25980, lbl_113_bss_1E8);
}

__declspec(section ".ctors") extern void* const fn_113_259C0_ctor = (void*)fn_113_259C0;
