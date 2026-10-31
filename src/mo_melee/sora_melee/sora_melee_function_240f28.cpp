#pragma force_active on
extern "C" {
void fn_80107040(void* p);
void fn_27_240F28();
extern void* g_IfAdvMngr;

void fn_27_240F28() {
    if (g_IfAdvMngr != 0) {
        fn_80107040(g_IfAdvMngr);
    }
}
}
