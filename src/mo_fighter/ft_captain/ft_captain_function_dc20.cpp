#pragma force_active on

extern "C" {
extern unsigned char lbl_100_bss_1C4[];
extern unsigned char lbl_100_bss_1B8[];
void fn_100_DC68(void*);
void* fn_100_DBE0(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_100_DC20(void)
{
    fn_100_DC68(lbl_100_bss_1C4);
    __register_global_object(lbl_100_bss_1C4, (void*)fn_100_DBE0, lbl_100_bss_1B8);
}

__declspec(section ".ctors") extern void* const fn_100_DC20_ctor = (void*)fn_100_DC20;
