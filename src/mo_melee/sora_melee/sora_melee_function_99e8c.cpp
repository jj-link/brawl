#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern void* g_ecMgr;
void fn_80060CE8(void* mgr, u32 a, u32 b);

void fn_27_99E8C(char* obj, u32 flags)
{
    u32 f = *(u32*)(obj + 0x48);
    fn_80060CE8(g_ecMgr, f | flags, flags | 0x00FFFF00);
}
}
