#pragma force_active on
extern "C" {
extern void* g_IfAdvMngr;
extern void* g_IfMngr;
void fn_801078A4(void* mngr, int arg);
void fn_800DCF04(void* mngr, int arg);
}

extern "C" void fn_40_15B48() {
    if (g_IfAdvMngr != 0) {
        fn_801078A4(g_IfAdvMngr, 0);
        fn_801078A4(g_IfAdvMngr, 1);
    }
    if (g_IfMngr != 0) {
        fn_800DCF04(g_IfMngr, 0);
        fn_800DCF04(g_IfMngr, 1);
    }
}
