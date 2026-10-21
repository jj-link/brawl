#include <stddef.h>
#pragma force_active on

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" {
void fn_122_14304(void *self);
void *fn_122_14270(void *p, short flag);
void *__register_global_object(void *object, void *destructor, DestructorChain *chain);
extern unsigned char lbl_122_bss_170[];
extern unsigned char lbl_122_bss_17C[];
}

extern "C" void fn_122_142BC(void) {
    fn_122_14304(lbl_122_bss_17C);
    __register_global_object(lbl_122_bss_17C, (void *)fn_122_14270, (DestructorChain *)lbl_122_bss_170);
}

__declspec(section ".ctors") extern void* const fn_122_142BC_ctor = (void*)fn_122_142BC;
