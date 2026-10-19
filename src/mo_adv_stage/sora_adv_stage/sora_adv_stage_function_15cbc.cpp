#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;
void fn_80107D18(char*);

void fn_40_15CBC(int unused, unsigned int count)
{
    if (g_IfAdvMngr != 0) {
        unsigned int i;
        for (i = 0; (unsigned char)i < count; i++) {
            fn_80107D18(g_IfAdvMngr);
        }
    }
}
}
