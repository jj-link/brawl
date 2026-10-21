#pragma force_active on
typedef struct DestructorChain DestructorChain;

extern "C" void* fn_113_26D48(void*, short);
extern "C" void fn_113_26DD0(void*);
extern "C" void* __register_global_object(void*, void*, DestructorChain*);

extern "C" unsigned char lbl_113_bss_26C[];
extern "C" unsigned char lbl_113_bss_260[];

extern "C" void fn_113_26D88(void)
{
    fn_113_26DD0(lbl_113_bss_26C);
    __register_global_object(
        lbl_113_bss_26C,
        (void*)fn_113_26D48,
        (DestructorChain*)lbl_113_bss_260
    );
}

__declspec(section ".ctors") extern void* const fn_113_26D88_ctor = (void*)fn_113_26D88;
