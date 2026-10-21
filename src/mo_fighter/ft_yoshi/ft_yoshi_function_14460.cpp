#pragma force_active on
typedef struct DestructorChain DestructorChain;

extern "C" {
void* fn_95_144A8(void*);
void* fn_95_14420(void*, short);
void* __register_global_object(void*, void*, DestructorChain*);
extern unsigned int lbl_95_bss_45C;
extern DestructorChain lbl_95_bss_450;
}

extern "C" void fn_95_14460(void)
{
    fn_95_144A8(&lbl_95_bss_45C);
    __register_global_object(&lbl_95_bss_45C, (void*)fn_95_14420, &lbl_95_bss_450);
}

__declspec(section ".ctors") extern void* const fn_95_14460_ctor = (void*)fn_95_14460;
