#include <types.h>
#pragma force_active on

extern "C" {
void fn_114_126E4(unsigned int* ptr);
void* fn_114_1265C(void* p, s16 flags);
extern unsigned int lbl_114_bss_22C;
extern unsigned char lbl_114_bss_220[0xC];
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_114_1269C(void) {
    fn_114_126E4(&lbl_114_bss_22C);
    __register_global_object(&lbl_114_bss_22C, (void*)fn_114_1265C, lbl_114_bss_220);
}
}

__declspec(section ".ctors") extern void* const fn_114_1269C_ctor = (void*)fn_114_1269C;
