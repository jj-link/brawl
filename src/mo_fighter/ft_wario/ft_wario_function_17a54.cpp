#include <stddef.h>
#pragma force_active on

extern "C" {

extern unsigned char lbl_110_bss_338[];
extern unsigned char lbl_110_bss_344[];

void fn_110_17A9C(void *object);
void *fn_110_17A14(void *object, short n);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_110_17A54(void)
{
    fn_110_17A9C(lbl_110_bss_344);
    __register_global_object(lbl_110_bss_344, (void *)fn_110_17A14, lbl_110_bss_338);
}

}

__declspec(section ".ctors") extern void* const fn_110_17A54_ctor = (void*)fn_110_17A54;
