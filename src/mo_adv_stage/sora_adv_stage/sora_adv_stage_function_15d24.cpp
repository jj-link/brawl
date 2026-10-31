#pragma force_active on
extern "C" {
extern void *g_IfAdvMngr;
void fn_80107D68(void *self);
void fn_40_15D24(void);
}

extern "C" void fn_40_15D24(void)
{
    if (g_IfAdvMngr != 0) {
        fn_80107D68(g_IfAdvMngr);
    }
}
