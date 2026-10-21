#include <types.h>
#pragma force_active on

struct LucasArray4 {
    unsigned int vtable;
    unsigned int arr[4][4];
};

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" LucasArray4* lbl_114_bss_1FC;
extern "C" DestructorChain lbl_114_bss_1F0;
extern "C" void fn_114_10DD4(LucasArray4** dst);
extern "C" void* fn_114_10D4C(void* p, s16 flags);
extern "C" void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern "C" void fn_114_10D8C() {
    fn_114_10DD4(&lbl_114_bss_1FC);
    __register_global_object(&lbl_114_bss_1FC, (void*)fn_114_10D4C, &lbl_114_bss_1F0);
}

__declspec(section ".ctors") extern void* const fn_114_10D8C_ctor = (void*)fn_114_10D8C;
