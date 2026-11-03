#include <gf/gf_homemenu.h>
#pragma force_active on

struct HomeMenuFlags {
    u32 : 13;
    u32 bans : 7;
    u32 : 12;
};

bool gfHomeMenu::setBan(u32 ban, u32 index)
{
    HomeMenuFlags& flags = *reinterpret_cast<HomeMenuFlags*>(reinterpret_cast<u8*>(this) + 0xB0);
    flags.bans = (flags.bans & ~(1u << index)) | (ban << index);
    if (ban != 0) {
        return *reinterpret_cast<s32*>(reinterpret_cast<u8*>(this) + 0xB4) == 0 &&
            !((*reinterpret_cast<u8*>(reinterpret_cast<u8*>(this) + 0xB1) >> 4) & 1) &&
            *reinterpret_cast<s32*>(reinterpret_cast<u8*>(this) + 0x9C) == 0;
    }
    return true;
}
