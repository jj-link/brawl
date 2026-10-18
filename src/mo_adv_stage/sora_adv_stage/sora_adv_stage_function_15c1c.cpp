#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;
}

extern "C" void fn_40_15C1C(int unused, int offset)
{
    if (g_IfAdvMngr == 0) {
        return;
    }
    char* p = g_IfAdvMngr + offset;
    p[0x6a] = 1;
}
