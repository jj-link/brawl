#include <stddef.h>
#pragma force_active on

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern void *lbl_104_bss_634;
extern DestructorChain lbl_104_bss_628;

extern "C" void fn_104_247F4(void *);
extern "C" void fn_104_2476C(void *, short);
extern "C" void *__register_global_object(void *, void *, DestructorChain *);

extern "C" void fn_104_247AC(void) {
    fn_104_247F4(&lbl_104_bss_634);
    __register_global_object(
        &lbl_104_bss_634,
        (void *)fn_104_2476C,
        &lbl_104_bss_628
    );
}

__declspec(section ".ctors") extern void* const fn_104_247AC_ctor = (void*)fn_104_247AC;
