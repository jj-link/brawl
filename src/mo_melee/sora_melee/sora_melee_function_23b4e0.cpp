#pragma force_active on
extern "C" {
extern unsigned int lbl_27_data_4D1D0;
extern unsigned int lbl_27_bss_5918;
}

extern "C" void fn_27_23B4E0(void)
{
    lbl_27_bss_5918 = lbl_27_data_4D1D0;
}

__declspec(section ".ctors") extern void* const fn_27_23B4E0_ctor = (void*)fn_27_23B4E0;
