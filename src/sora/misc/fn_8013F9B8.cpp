#include <types.h>
#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" {
int fn_800D278C(void* self, int idx);
void fn_800D2164(void* self, int idx, u8 value);
extern void* lbl_805A0390;
extern u8 lbl_8059E742;
extern const f32 lbl_805A2AC8;
extern const f32 lbl_805A2B14;
extern const f32 lbl_805A2B18;
}

extern "C" void fn_8013F9B8(char* arg0) {
    muWifiInterfaceTask* task = g_muWifiInterfaceTask;
    u32 i;
    for (i = 0; i < 4; i++) {
        if ((u8)i == lbl_8059E742) {
            continue;
        }
        u32 off = (u8)i << 5;
        if (*(s8*)(arg0 + off + 0xB0) != 0) {
            int r = fn_800D278C(task, (u8)i);
            if (r < 0) {
                continue;
            }
            ntFriendInfo::getInstance();
            f32 f = *(f32*)((char*)lbl_805A0390 + off + 0xBC);
            u32 n = (u32)f / (*(u32*)0x800000F8 / 4 / 1000);
            f32 x = (f32)n - lbl_805A2B14;
            if (x < lbl_805A2AC8) {
                x = lbl_805A2AC8;
            }
            s32 level = (s32)(x / lbl_805A2B18);
            if (level > 4) {
                level = 4;
            }
            fn_800D2164(task, r, (u8)(5 - level));
        }
    }
}
