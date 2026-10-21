#pragma force_active on
extern "C" {
extern unsigned int lbl_805A0578;
extern unsigned int *lbl_805A0628;
}

extern "C" void fn_801D3C48(void)
{
    lbl_805A0628 = &lbl_805A0578;
}

__declspec(section ".ctors") extern void* const fn_801D3C48_ctor = (void*)fn_801D3C48;
