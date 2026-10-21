#include <types.h>
#pragma force_active on

struct fn94Obj {
    s32 unk0;
};

struct DestructorChain {
    DestructorChain* next;
    void* destructor;
    void* object;
};

extern "C" {
extern fn94Obj lbl_94_bss_30C;
extern DestructorChain lbl_94_bss_300;
void fn_94_1A074(fn94Obj* self);
fn94Obj* fn_94_19FEC(fn94Obj* self, short flag);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
}

extern "C" void fn_94_1A02C() {
    fn_94_1A074(&lbl_94_bss_30C);
    __register_global_object(&lbl_94_bss_30C, (void*)fn_94_19FEC, &lbl_94_bss_300);
}

__declspec(section ".ctors") extern void* const fn_94_1A02C_ctor = (void*)fn_94_1A02C;
