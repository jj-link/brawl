#pragma force_active on
typedef void (*Destructor)(void);

extern "C" void fn_95_138AC(void*);
extern "C" void fn_95_13824(void*, short);
extern "C" void __register_global_object(void*, void*, void*);

extern "C" void fn_95_13864(void)
{
    extern char lbl_95_bss_41C[];
    extern char lbl_95_bss_410[];

    fn_95_138AC(lbl_95_bss_41C);
    __register_global_object(
        lbl_95_bss_41C,
        (void*)fn_95_13824,
        lbl_95_bss_410);
}

__declspec(section ".ctors") extern void* const fn_95_13864_ctor = (void*)fn_95_13864;
