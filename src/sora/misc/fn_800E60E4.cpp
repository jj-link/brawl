#include <gm/gm_global.h>
#include <mu/mu_msg.h>
#pragma force_active on
extern "C" void fn_800E636C(u8*, u32, u32, s32);
extern "C" void fn_800E6608(u8*, u32, s32, s32);

extern "C" void fn_800E60E4(u8* self, s32 index) {
    s32 line = index * 4;
    u8* player;
    u8* result = (u8*)g_GameGlobal->m_resultInfo;
    u32 kills;
    if (*(s32*)(self + 0xA8 + line) == 3) return;
    player = result + index * 0x2AC;
    if (self[0xD4]) {
        fn_800E636C(self, line + 3, *(u32*)(player + 0x34), 1);
        fn_800E636C(self, line + 4, *(u32*)(player + 0x38), 0);
        u32 deaths = *(u32*)(player + 0x38);
        kills = *(u32*)(player + 0x34);
        if (kills < deaths) {
            (*(MuMsg**)(self + 0x650))->setFontColor(line + 6, 0xD2, 0x9F, 0x9F, 0xFF);
            fn_800E636C(self, line + 6, deaths - kills, 0);
        } else {
            (*(MuMsg**)(self + 0x650))->setFontColor(line + 6, 0x90, 0xC9, 0xEB, 0xFF);
            fn_800E636C(self, line + 6, kills - deaths, 1);
        }
    } else if (result[1] == 2) {
        fn_800E636C(self, line + 3, *(u32*)(player + 0x50), 1);
        fn_800E636C(self, line + 4, *(u32*)(player + 0x50) - *(u32*)(player + 0x4C), 0);
        (*(MuMsg**)(self + 0x650))->setFontColor(line + 6, 0x90, 0xC9, 0xEB, 0xFF);
        fn_800E636C(self, line + 6, *(u32*)(player + 0x4C), 1);
    } else {
        u16 suicides = *(u16*)(player + 0x3C);
        u32 total;
        s32 penalty = -(suicides * (s8)result[3]);
        u32 deaths = *(u32*)(player + 0x38) - suicides;
        fn_800E636C(self, line + 3, *(u32*)(player + 0x34), 1);
        fn_800E636C(self, line + 4, deaths, 0);
        fn_800E636C(self, line + 5, penalty, 0);
        if (result[1] == 0) {
            u32 kills = *(u32*)(player + 0x34);
            total = deaths + penalty;
            if (kills < total) {
                (*(MuMsg**)(self + 0x650))->setFontColor(line + 6, 0xD2, 0x9F, 0x9F, 0xFF);
                fn_800E636C(self, line + 6, total - kills, 0);
            } else {
                (*(MuMsg**)(self + 0x650))->setFontColor(line + 6, 0x90, 0xC9, 0xEB, 0xFF);
                fn_800E636C(self, line + 6, kills - deaths - penalty, 1);
            }
        } else if ((s8)player[0x2E] > 0 || result[0x1378] == 9) {
            fn_800E6608(self, line + 6, 0, 0);
        } else {
            fn_800E6608(self, line + 6, *(s32*)(player + 0x278), 1);
        }
    }
}
