#pragma force_active on
extern "C" {
extern void *g_ftSlotManager;
void fn_27_11D32C(void *, void *, int, int);

void fn_27_10961C(void *p1, int p2, void *p3)
{
    fn_27_11D32C((char *)*(void **)g_ftSlotManager + p2 * 0x4D4, p3, 0x4000, 0);
}
}
