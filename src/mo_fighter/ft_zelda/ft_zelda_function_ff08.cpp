#include <stddef.h>
#pragma force_active on

typedef struct DestructorChain
{
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
void fn_104_FF50(void *obj);
void *fn_104_FEC8(void *ptr, short size);
void *__register_global_object(void *object, void *destructor, DestructorChain *chain);
extern char lbl_104_bss_1F4[4];
extern DestructorChain lbl_104_bss_1E8;
}

extern "C" void fn_104_FF08(void)
{
    fn_104_FF50(lbl_104_bss_1F4);
    __register_global_object(lbl_104_bss_1F4, (void *)fn_104_FEC8, &lbl_104_bss_1E8);
}

__declspec(section ".ctors") extern void* const fn_104_FF08_ctor = (void*)fn_104_FF08;
