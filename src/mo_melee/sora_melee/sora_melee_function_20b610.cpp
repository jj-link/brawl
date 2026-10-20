#pragma force_active on
extern "C" {
extern void *g_aiMgr;
extern float lbl_27_rodata_2F68;
extern float lbl_27_rodata_2FD0;
void fn_27_1ED8A4(void *a, int b, int c, int d, int e, float f1, float f2, float f3);
void fn_27_20B610(int unused, int b);
}

extern "C" void fn_27_20B610(int unused, int b)
{
    fn_27_1ED8A4(g_aiMgr, b, 0, 0, -1, lbl_27_rodata_2FD0, lbl_27_rodata_2F68, lbl_27_rodata_2F68);
}
