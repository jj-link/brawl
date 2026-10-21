#include <types.h>
#pragma force_active on

struct LucasArrayAggregate;

extern "C" void fn_114_10CC8(LucasArrayAggregate* arrays);
extern "C" void* fn_114_10C40(void* object, s16 flag);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

extern "C" u32 lbl_114_bss_1EC;
extern "C" u32 lbl_114_bss_1E0[3];

extern "C" void fn_114_10C80() {
    fn_114_10CC8((LucasArrayAggregate*)&lbl_114_bss_1EC);
    __register_global_object(&lbl_114_bss_1EC, (void*)fn_114_10C40, lbl_114_bss_1E0);
}

__declspec(section ".ctors") extern void* const fn_114_10C80_ctor = (void*)fn_114_10C80;
