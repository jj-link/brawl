#pragma force_active on

typedef void (*Destructor)(void*, int);

extern "C" void* fn_95_142E0(void*, int);
extern "C" void fn_95_14368(void*);
extern "C" void* __register_global_object(void*, Destructor, void**);
extern "C" char lbl_95_bss_44C[];
extern "C" char lbl_95_bss_440[];

extern "C" void fn_95_14320()
{
    fn_95_14368(lbl_95_bss_44C);
    __register_global_object(lbl_95_bss_44C, (Destructor)fn_95_142E0, (void**)lbl_95_bss_440);
}

__declspec(section ".ctors") extern void* const fn_95_14320_ctor = (void*)fn_95_14320;
