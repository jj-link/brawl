#pragma force_active on
struct IfAdvMngr;
extern IfAdvMngr* g_IfAdvMngr;
extern "C" void* fn_80107834(void);

extern "C" void* fn_40_15C5C(void)
{
    if (g_IfAdvMngr != 0) {
        return fn_80107834();
    }
    return g_IfAdvMngr;
}
