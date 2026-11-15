#include <types.h>
#pragma force_active on

extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" void fn_8004D010(void* game);
extern "C" s32 fn_80052DB0(void* p);
extern "C" s32 OSGetTick();
extern "C" void srandi__Fl(s32 seed);
extern "C" u8* g_GameGlobal;

struct Flags2E {
    u8 mode : 3;
    u8 rest : 5;
};

extern "C" void fn_1_29358(u8* self) {
    u8* mgr = (u8*)getInstance__14gfSceneManagerFv();
    if (*(s32*)(mgr + 0x31C) == 0xFF) {
        *(s32*)(self + 8) = 0x10;
        return;
    }
    *(u8*)(*(u8**)(g_GameGlobal + 0x30) + 0x603) = 0;
    *(s32*)(self + 8) = 0;
    fn_8004D010(g_GameGlobal);
    u8* p = *(u8**)(g_GameGlobal + 0x10);
    ((Flags2E*)(p + 0x2E))->mode = 1;
    s32 ret = fn_80052DB0(p);
    u8* q = *(u8**)(g_GameGlobal + 0x30);
    if (q != 0) {
        q[0x4928] = 0;
        *(s32*)(*(u8**)(g_GameGlobal + 0x30) + 0x492C) = ret;
    }
    u8* q2 = *(u8**)(g_GameGlobal + 0x30);
    if (q2 != 0) {
        q2[0x4930] = 0;
        *(s32*)(*(u8**)(g_GameGlobal + 0x30) + 0x4934) = -1;
    }
    srandi__Fl(OSGetTick());
}