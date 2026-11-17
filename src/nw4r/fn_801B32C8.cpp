#include <types.h>
#pragma force_active on
struct Val { s32 v; };
extern "C" void fn_801AFB78(void*, void*, Val, s32, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_804663C8[];
struct Block { u32 v[16]; };
extern "C" void* fn_801B32C8(void* self, void* a1, Val a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, Block a10, s32 a11, s32 a12) {
    fn_801AFB78(self, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    u8* p = (u8*)self;
    *(u32*)(p + 0x138) = 0;
    *(void**)p = lbl_804663C8;
    *(u32*)(p + 0x13c) = 0;
    *(s32*)(p + 0x140) = a11;
    *(Block*)(p + 0x144) = a10;
    *(s32*)(p + 0x184) = a12;
    return self;
}
