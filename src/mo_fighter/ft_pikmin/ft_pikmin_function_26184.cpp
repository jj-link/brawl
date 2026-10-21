#include <stddef.h>
#pragma force_active on

typedef struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
} DestructorChain;

extern "C" void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
extern "C" void fn_113_261CC(void* self);
extern "C" void* fn_113_26144(void* ptr, short count);

extern "C" int lbl_113_bss_234;
extern "C" DestructorChain lbl_113_bss_228;

extern "C" void fn_113_26184() {
    fn_113_261CC(&lbl_113_bss_234);
    __register_global_object(&lbl_113_bss_234, (void*)fn_113_26144, &lbl_113_bss_228);
}

__declspec(section ".ctors") extern void* const fn_113_26184_ctor = (void*)fn_113_26184;
