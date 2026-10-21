#include <types.h>
#pragma force_active on

extern "C" {

extern void* lbl_114_bss_23C;
extern void* lbl_114_bss_230;

extern void fn_114_127F0(void** ptr);
extern void* fn_114_12768(void* p, s16 flag);

void* __register_global_object(void* object, void* destructor, void* chain);

void fn_114_127A8(void) {
    fn_114_127F0(&lbl_114_bss_23C);
    __register_global_object(&lbl_114_bss_23C, (void*)&fn_114_12768, &lbl_114_bss_230);
}

}

__declspec(section ".ctors") extern void* const fn_114_127A8_ctor = (void*)fn_114_127A8;
