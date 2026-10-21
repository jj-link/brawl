#pragma force_active on
struct BssPair {
    int a;
    int b;
};

extern "C" {
extern struct BssPair lbl_68_bss_58;
extern struct BssPair lbl_68_bss_60;

void fn_68_E6C4(void)
{
    lbl_68_bss_58.a = 0xff;
    lbl_68_bss_58.b = 0;
    lbl_68_bss_60.a = 0xff;
    lbl_68_bss_60.b = 1;
}
}

__declspec(section ".ctors") extern void* const fn_68_E6C4_ctor = (void*)fn_68_E6C4;
