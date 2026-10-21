#pragma force_active on
extern "C" {
void fn_113_25FA8(void* p);
void* fn_113_25F20(void* ptr, short count);
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);

extern char lbl_113_bss_218[12];
extern char lbl_113_bss_224[4];

void fn_113_25F60(void)
{
    fn_113_25FA8(lbl_113_bss_224);
    __register_global_object(lbl_113_bss_224, fn_113_25F20, lbl_113_bss_218);
}
}

__declspec(section ".ctors") extern void* const fn_113_25F60_ctor = (void*)fn_113_25F60;
