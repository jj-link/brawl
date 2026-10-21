#pragma force_active on
extern "C" {
extern char lbl_94_bss_41C[8];
extern char lbl_94_bss_424[8];
void fn_94_19BD8(void *p, int a, void *b);

void fn_94_203A0()
{
    fn_94_19BD8(lbl_94_bss_41C, 0xff, (void *)0);
    fn_94_19BD8(lbl_94_bss_424, 0xff, (void *)1);
}
}

__declspec(section ".ctors") extern void* const fn_94_203A0_ctor = (void*)fn_94_203A0;
