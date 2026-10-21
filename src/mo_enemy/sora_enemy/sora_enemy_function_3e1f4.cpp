#pragma force_active on
extern "C" void fn_41_C614(unsigned int* p1, unsigned int p2, unsigned int p3);

extern "C" unsigned int lbl_41_bss_400[2];
extern "C" unsigned int lbl_41_bss_408[2];

extern "C" {
void fn_41_3E1F4()
{
    fn_41_C614(lbl_41_bss_400, 0xff, 0);
    fn_41_C614(lbl_41_bss_408, 0xff, 1);
}
}

__declspec(section ".ctors") extern void* const fn_41_3E1F4_ctor = (void*)fn_41_3E1F4;
