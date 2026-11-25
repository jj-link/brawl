#include <types.h>
#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern "C" int fn_803517BC(void*, void*);
extern "C" int fn_800D278C(void*, int);
extern "C" void fn_800D38EC(void*, int, int);
extern unsigned char lbl_805A03D0;
extern void* lbl_805A0434;
extern char lbl_8045FAC8[];
extern char lbl_8045FAFC[];

extern "C" void fn_8014847C(int index) {
    while (lbl_805A03D0 != 0 && *(unsigned char*)((char*)lbl_805A0434 + 0x33CC) == 0) {
        OSSleepTicks((s64)((*(u32*)0x800000F8 >> 2) / 1000));
    }
    char* info = (char*)ntFriendInfo::getInstance()->getFriendInfo();
    char* task = (char*)g_muWifiInterfaceTask;
    int value = fn_803517BC(info + 0x10, info + index * 12 + 0x50);
    for (unsigned int i = 0; i < 4; i++) {
        if (fn_800D278C(task, (u8)i) < 0) {
            s64 key = *(s64*)(task + (u8)i * 0x218 + 0x248);
            if (key == value) {
                fn_800D38EC(task, (u8)i, index >= 0);
                netReport(lbl_8045FAC8, (u8)i, index);
            }
        }
    }
    netReport(lbl_8045FAFC, index);
}
