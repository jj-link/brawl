#pragma force_active on
extern "C" void exit__6gfTaskFv(void*);

extern void* lbl_40_bss_7C0;

extern "C" {
void fn_40_172E0()
{
    exit__6gfTaskFv(lbl_40_bss_7C0);
    lbl_40_bss_7C0 = 0;
}
}
