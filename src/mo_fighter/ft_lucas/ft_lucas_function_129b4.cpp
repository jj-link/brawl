#include <types.h>
#pragma force_active on

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
void fn_114_129FC(u32* obj);
void* fn_114_12974(void* object, s16 flags);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);

extern u32 lbl_114_bss_24C;
extern u32 lbl_114_bss_240[3];
}

extern "C" void fn_114_129B4() {
    fn_114_129FC(&lbl_114_bss_24C);
    __register_global_object(&lbl_114_bss_24C, (void*)fn_114_12974, (DestructorChain*)&lbl_114_bss_240[0]);
}

__declspec(section ".ctors") extern void* const fn_114_129B4_ctor = (void*)fn_114_129B4;
