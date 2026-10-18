#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;

void fn_40_15C3C(int unused, int off)
{
    char* p = g_IfAdvMngr;
    if (p == 0) {
        return;
    }
    p += off;
    p[0x68] = 1;
}
}
