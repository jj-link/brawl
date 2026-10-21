#pragma force_active on
extern "C" {
void fn_96_14364(void *object);
void *fn_96_142DC(void *p, short n);
void *__register_global_object(void *object, void *destructor, void *chain);

extern unsigned char lbl_96_bss_C4C[];
extern unsigned char lbl_96_bss_C40[];

void fn_96_1431C(void)
{
    fn_96_14364(lbl_96_bss_C4C);
    __register_global_object(lbl_96_bss_C4C, (void *)fn_96_142DC, lbl_96_bss_C40);
}
}

__declspec(section ".ctors") extern void* const fn_96_1431C_ctor = (void*)fn_96_1431C;
