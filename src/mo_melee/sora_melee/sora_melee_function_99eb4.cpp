#pragma force_active on
typedef unsigned int u32;

extern void *g_ecMgr;

extern "C" u32 fn_80060E20(void *mgr, u32 a, u32 b, u32 c, u32 d, u32 e);

extern "C" u32 fn_27_99EB4(u32 self, u32 a, u32 b, u32 c)
{
    return fn_80060E20(g_ecMgr, *(u32 *)(self + 0x48), 0x100 * 0x10000 - 0x100, b, c, a);
}
