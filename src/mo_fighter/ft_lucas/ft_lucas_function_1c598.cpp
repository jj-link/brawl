#include <types.h>
#pragma force_active on

extern "C" {
extern const u32* lbl_114_bss_43C;
extern u8 lbl_114_bss_430[12];

void fn_114_1C5E0(const u32** out);
void* fn_114_1C558(void* object, s16 flags);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_114_1C598(void) {
    fn_114_1C5E0(&lbl_114_bss_43C);
    __register_global_object(&lbl_114_bss_43C, (void*)fn_114_1C558, lbl_114_bss_430);
}
}

__declspec(section ".ctors") extern void* const fn_114_1C598_ctor = (void*)fn_114_1C598;
