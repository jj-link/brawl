#pragma force_active on
extern "C" void fn_800DB444();
extern "C" void fn_800DF848(void*);
extern "C" void fn_801AAF04(void*, int, void*);
extern unsigned char lbl_805A02E4;

extern "C" void fn_800DF7DC(char* a, int b, void* c) {
    if (b == 2) {
        if (lbl_805A02E4 != 0) {
            lbl_805A02E4 = 0;
            fn_800DB444();
        }
        fn_800DF848(a);
        fn_801AAF04(c, 1, a + 4);
    }
}
