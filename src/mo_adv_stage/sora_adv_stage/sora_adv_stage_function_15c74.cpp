#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;
void fn_80107834(char*, int);

void fn_40_15C74()
{
    if (g_IfAdvMngr != 0) {
        fn_80107834(g_IfAdvMngr, 0);
        fn_80107834(g_IfAdvMngr, 1);
    }
}
}
