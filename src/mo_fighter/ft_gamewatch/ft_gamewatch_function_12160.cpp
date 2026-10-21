#pragma force_active on
extern "C" {
void fn_107_121A8(void* object);
void* fn_107_12120(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern char lbl_107_bss_16C[];
extern char lbl_107_bss_160[];
}

extern "C" void fn_107_12160()
{
    fn_107_121A8(lbl_107_bss_16C);
    __register_global_object(lbl_107_bss_16C, (void*)fn_107_12120, lbl_107_bss_160);
}

__declspec(section ".ctors") extern void* const fn_107_12160_ctor = (void*)fn_107_12160;
