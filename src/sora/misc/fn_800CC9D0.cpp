#pragma force_active on
#include <types.h>

struct ntFriendInfo {
    u8 pad[0x6C];
    u32 state;
    u8 pad2[0xF68];
    u8 count;
};

extern "C" void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457F94[];

extern "C" s32 fn_800CC9D0(ntFriendInfo* self) {
    u8 count = self->count;
    if (count >= 0x40) {
        return 0;
    }

    u8* base = (u8*)*getInstance__12ntFriendInfoFv(self) + count * 0x89;
    u8 t = *(base + 0x608);
    switch (t) {
    case 19:
    case 23:
    case 25:
        return (u32)__cntlzw(self->state) >> 5;
    case 20:
    case 26:
        return (u32)__cntlzw(self->state - 1) >> 5;
    case 21:
    case 27:
        return (u32)__cntlzw(self->state - 2) >> 5;
    default:
        netReport__FPCce(lbl_80457F94, self->state, t);
        return 0;
    }
}
