#include <types.h>
#include <nt/nt_offline.h>
#include <nt/network.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on
extern "C" s32 fn_800C9A4C(u32);
extern "C" void fn_80146878(void*, int);
extern "C" void fn_801473C4();
extern s32 gUnk805a03d8;
extern s32 lbl_805A03F0;
extern s32 g_NtMatchingStatus;
extern char lbl_80457F94[];
extern char lbl_80457FEC[];

extern "C" s32 fn_800CCA9C(void* arg0, s32* arg1, s32* arg2) {
    if (arg2 != 0) *arg2 = 0;
    if (arg1 != 0) *arg1 = 0;
    if (gUnk805a03d8 == 0) return 0;
    if (lbl_805A03F0 != 0) {
        if (arg2 != 0) *arg2 = lbl_805A03F0;
        if (arg1 != 0) *arg1 = fn_800C9A4C(*arg2);
        return 3;
    }
    s32 step = *(s32*)((char*)arg0 + 0xfcc) >> 24;
    if (step == 6) {
        fn_80146878(&g_Network, 0);
        *(s32*)((char*)arg0 + 0x1048) = 0;
        *(s32*)((char*)arg0 + 0x104c) = 0;
        fn_801473C4();
        return 7;
    }
    if (step == 7) {
        fn_80146878(&g_Network, 0);
        *(s32*)((char*)arg0 + 0x1048) = 0;
        *(s32*)((char*)arg0 + 0x104c) = 0;
        fn_801473C4();
        return 6;
    }
    if (step == 5) {
        fn_80146878(&g_Network, 0);
        *(s32*)((char*)arg0 + 0x1048) = 0;
        *(s32*)((char*)arg0 + 0x104c) = 0;
        fn_801473C4();
        return 6;
    }
    if (step != 4) {
        bool equal;
        u8 index = *(u8*)((char*)arg0 + 0xfd8);
        if (index >= 64) equal = false;
        else {
            ntFriendInfo* info = ntFriendInfo::getInstance();
            u8 status = *((u8*)*(void**)info + index * 0x89 + 0x608);
            switch (status) {
            case 19: case 23: case 25:
                equal = *(s32*)((char*)arg0 + 0x6c) == 0;
                break;
            case 20: case 26:
                equal = *(s32*)((char*)arg0 + 0x6c) == 1;
                break;
            case 21: case 27:
                equal = *(s32*)((char*)arg0 + 0x6c) == 2;
                break;
            default:
                netReport(lbl_80457F94, *(s32*)((char*)arg0 + 0x6c), status);
                equal = false;
                break;
            }
        }
        if (!equal) {
            netReport(lbl_80457FEC, *(s32*)((char*)arg0 + 0xfcc) >> 24);
            fn_80146878(&g_Network, 0);
            *(s32*)((char*)arg0 + 0x1048) = 0;
            *(s32*)((char*)arg0 + 0x104c) = 0;
            fn_801473C4();
            return 6;
        }
    }
    bool flag = g_NtMatchingStatus == 7 || g_NtMatchingStatus <= 8;
    s32 result = 2;
    if (flag != 0) result = 1;
    return result;
}