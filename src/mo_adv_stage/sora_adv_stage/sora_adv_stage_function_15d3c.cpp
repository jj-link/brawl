#pragma force_active on
extern "C" {
extern void* g_IfAdvMngr;
void fn_80107D68(void* p);

void fn_40_15D3C() {
    if (g_IfAdvMngr != 0) {
        int n = *(int*)((char*)g_IfAdvMngr + 0x10c);
        for (int i = 0; i < n; i++) {
            fn_80107D68(g_IfAdvMngr);
        }
    }
}
}
