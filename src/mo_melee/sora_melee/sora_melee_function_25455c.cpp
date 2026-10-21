#pragma force_active on
struct Pair {
    int a;
    int b;
};

extern "C" struct Pair lbl_27_bss_59B0;
extern "C" struct Pair lbl_27_bss_59B8;

extern "C" void fn_27_25455C() {
    lbl_27_bss_59B0.a = 0xff;
    lbl_27_bss_59B0.b = 0;
    lbl_27_bss_59B8.a = 0xff;
    lbl_27_bss_59B8.b = 1;
}

__declspec(section ".ctors") extern void* const fn_27_25455C_ctor = (void*)fn_27_25455C;
