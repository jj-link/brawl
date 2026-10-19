#pragma force_active on
extern "C" {
extern void* g_IfWifiprMngr;
void fn_800FC920(void* p);
void fn_800FCB84(void* p);
void fn_27_2410F8();
}

void fn_27_2410F8() {
    fn_800FC920(g_IfWifiprMngr);
    fn_800FCB84(g_IfWifiprMngr);
}
