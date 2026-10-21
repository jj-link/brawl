#pragma force_active on
struct Pair {
    int a;
    int b;
};

extern "C" struct Pair lbl_66_bss_50;
extern "C" struct Pair lbl_66_bss_58;

extern "C" void fn_66_EF20()
{
    lbl_66_bss_50.a = 0xff;
    lbl_66_bss_50.b = 0;
    lbl_66_bss_58.a = 0xff;
    lbl_66_bss_58.b = 1;
}

__declspec(section ".ctors") extern void* const fn_66_EF20_ctor = (void*)fn_66_EF20;
