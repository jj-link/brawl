#pragma force_active on
struct bssPair {
    unsigned int a;
    int b;
};

extern "C" struct bssPair lbl_27_bss_5990;
extern "C" struct bssPair lbl_27_bss_5998;

extern "C" void fn_27_247D68() {
    lbl_27_bss_5990.a = 0xFF;
    lbl_27_bss_5990.b = 0;
    lbl_27_bss_5998.a = 0xFF;
    lbl_27_bss_5998.b = 1;
}

__declspec(section ".ctors") extern void* const fn_27_247D68_ctor = (void*)fn_27_247D68;
