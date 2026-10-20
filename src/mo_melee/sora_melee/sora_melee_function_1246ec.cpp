#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" u8 fn_27_1F1B2C(u8* self, s32 idx);
extern void* g_aiMgr;

extern "C" u8 fn_27_1246EC(u8* self)
{
    u8* inner = *(u8**)(self + 0x4);
    s32 idx = *(s32*)(inner + 0x58);
    return fn_27_1F1B2C((u8*)g_aiMgr, idx);
}
