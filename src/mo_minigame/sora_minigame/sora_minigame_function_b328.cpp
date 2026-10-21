#pragma force_active on
struct Pair {
    unsigned int value;
    unsigned int flag;
};

extern Pair lbl_20_bss_20;
extern Pair lbl_20_bss_28;

extern "C" void fn_20_B328(void)
{
    lbl_20_bss_20.value = 0xff;
    lbl_20_bss_20.flag = 0;
    lbl_20_bss_28.value = 0xff;
    lbl_20_bss_28.flag = 1;
}

__declspec(section ".ctors") extern void* const fn_20_B328_ctor = (void*)fn_20_B328;
