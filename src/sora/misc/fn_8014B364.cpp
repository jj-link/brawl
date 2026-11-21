#include <types.h>
#include <string.h>
#include <nt/nt_offline.h>
#include <nt/d_net_connect.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSTime.h>
#include <revolution/DWC/dwc_init.h>
#include <revolution/DWC/dwc_main.h>
#include <revolution/DWC/neterrorcode.h>

#pragma force_active on

class BufferInterface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void release();
};

extern "C" {
extern char lbl_8045F7A8[];
extern int g_NtMatchingStatus;
extern int lbl_805A03E0;
extern u8 lbl_805A03E4;
extern int lbl_805A03E8;
extern int lbl_805A03F0;
extern int lbl_805A03F4;
extern int lbl_805A03FC;
extern int g_NtAIDBitmap;
extern int lbl_805A0410;
extern u8 lbl_805A0414;
extern u8 lbl_805A0418[8];
extern u8* lbl_805A0430;
extern u8* lbl_805A0434;
extern u8 lbl_805A0438;
extern int lbl_805A043C;
extern int lbl_805A0440;
extern int lbl_805A0444;
extern u8 lbl_805A03D0;
extern u8 lbl_8059E740;
extern u8 lbl_8059E742;
extern u8 lbl_8059E743;
extern u8 lbl_8059E744;
extern u8 lbl_8059E745;
extern int lbl_8059E7B8;
extern u32 lbl_8059E7C8;
extern int g_80409650[];

void fn_801473AC();
void fn_80146FCC(int);
void fn_8014B130(int);
void fn_8014A834();
void fn_800D2580(void*, u16*);
void* fn_8014CB40(ntFriendInfo*);
int fn_8014CB4C(ntFriendInfo*, void*);
void fn_8014CB7C(ntFriendInfo*);
void fn_80351F7C(void*);
void fn_80335630(int);
void fn_803359CC();
void fn_80336AC8(void (*)(), void*);
void fn_80339E98(int, void (*)(), int, void (*)(), int, void (*)(), int);
void fn_8034E57C(int);
void fn_801572DC(void*, int);
void fn_800C8F68(const char*, ...);

void* fn_801499E4(int, u32, int);
void fn_80149A4C(int, void*, int);
void fn_8014847C();
void fn_80148810(s32, s32, void*);
void fn_80148210();
void fn_80148280();
void fn_801482C8();
}

extern "C" int fn_8014B364() {
    char* base = lbl_8045F7A8;
    struct {
        char login[12];
        u16 value;
        char padding[14];
    } locals;

    g_NtMatchingStatus = 0;
    lbl_805A03E0 = 0;
    lbl_805A03E4 = 0;
    lbl_805A0438 = 0;
    fn_801473AC();
    fn_80146FCC(0);
    netReport(base + 0x1120);

    int result = dNetConnect_Start();
    if (result < 0) {
        int error = -NETGetStartupErrorCode(result);
        netReport(base + 0x1140, result, error);
        fn_8014B130(1);
        lbl_805A03F0 = error;
        lbl_805A03F4 = 3;
        while (lbl_805A0434[0x33CC] == 0) {
            OSSleepTicks((s64)((OS_BUS_CLOCK_SPEED / 4) / 1000) * 16);
        }
    } else {
        fn_80146FCC(1);
        netReport(base + 0x1164);
        int init = DWC_Init(1, base + 0xB70, lbl_8059E7C8,
                            fn_801499E4, fn_80149A4C);
        if (init < 0) {
            netReport(base + 0x1170, init);
        }

        u8 index = lbl_8059E740;
        lbl_805A0438 = 1;
        int setting = g_80409650[index];
        lbl_8059E740 = index;
        fn_80335630(setting);
        fn_80146FCC(2);

        while (lbl_805A03D0 && lbl_805A0434[0x33CC] == 0) {
            OSSleepTicks((OS_BUS_CLOCK_SPEED / 4) / 1000);
        }

        fn_800D2580(g_muWifiInterfaceTask, &locals.value);
        ntFriendInfo* info = ntFriendInfo::getInstance();
        int valid;
        if (fn_8014CB4C(info, fn_8014CB40(info)) == 0) {
            valid = 0;
        } else {
            fn_80351F7C(fn_8014CB40(info));
            valid = 1;
        }

        if (!valid || locals.value == 0) {
            netReport(base + 0xB40);
            info = ntFriendInfo::getInstance();
            fn_8014CB7C(info);
            fn_80351F7C(fn_8014CB40(info));
            netReport(base + 0xB58);
            lbl_805A0434[0x343C] = 1;
        }

        memset(&lbl_805A0444, 0, 4);
        u8* friendInfo = (u8*)ntFriendInfo::getInstance()->getFriendInfo();
        DWC_InitFriendsMatch((s32)&lbl_805A0444, (s32)(friendInfo + 0x10),
                             0x2B1E, (s32)(base + 0xB70),
                             (s32)&lbl_8059E7B8, 0, 0,
                             (s32)(friendInfo + 0x50), 0x40);
        fn_80336AC8(fn_8014847C, 0);
        memset(locals.login, 0, sizeof(locals.login));
        if (!DWC_LoginAsync((s32)locals.login, 0, fn_80148810, 0)) {
            netReport(base + 0xB80);
        }
        fn_80339E98(0, fn_80148210, 0, fn_80148280, 0, fn_801482C8, 0);
        fn_80146FCC(3);
        lbl_805A043C = 0;
        lbl_805A0440 = 1;
        lbl_805A03E4 = 1;
        lbl_805A0434[0x33F4] = 1;
        *(u16*)(lbl_805A0434 + 0x3422) = 0x1C20;

        do {
            fn_8014A834();
            if (lbl_805A0434[0x33CC] != 0) {
                break;
            }
            OSSuspendThread((OSThread*)(lbl_805A0434 + 0xA0));
        } while (true);

        if (lbl_805A0430 != 0) {
            netReport(base + 0x1194);
            while (lbl_805A0430[0x374] == 0) {
                OSSleepTicks((s64)((OS_BUS_CLOCK_SPEED / 4) / 1000) * 16);
            }
            fn_801572DC(lbl_805A0430, 1);
            lbl_805A0430 = 0;
        }

        int status = (g_NtMatchingStatus != 12) ? g_NtMatchingStatus : lbl_805A03E0;
        fn_80146FCC(11);
        if (status >= 2 && status <= 10) {
            fn_8034E57C(0);
            DWC_ShutdownFriendsMatch();
            lbl_805A03FC = 0;
            if (lbl_805A03E8 == 7) {
                netReport(base + 0x11AC, lbl_805A03F0, lbl_805A03F4);
                fn_800C8F68(base + 0x11AC, lbl_805A03F0, lbl_805A03F4);
                if (lbl_805A03F4 == 4) {
                    netReport(base + 0x11C8);
                    fn_803359CC();
                    fn_803359CC();
                    fn_803359CC();
                    fn_803359CC();
                }
            }
            DWC_Shutdown();
            lbl_805A0438 = 0;
        }
    }

    netReport(base + 0x11D8);
    dNetConnect_Finish();
    lbl_805A03E4 = 0;
    fn_80146FCC(0);
    lbl_805A03E0 = 0;
    ((BufferInterface*)(lbl_805A0434 + 0x33B8))->release();
    memset(&lbl_805A0410, 0, 4);
    g_NtAIDBitmap = 0;
    lbl_805A0414 = 0;
    lbl_8059E742 = 0xFF;
    lbl_8059E745 = 0xFF;
    lbl_8059E743 = 0xFF;
    lbl_8059E744 = 0xFF;
    lbl_805A0418[0] = 0;
    lbl_805A0418[1] = 0;
    lbl_805A0418[2] = 0;
    lbl_805A0418[3] = 0;
    lbl_805A0418[4] = 0;
    lbl_805A0418[5] = 0;
    lbl_805A0418[6] = 0;
    lbl_805A0418[7] = 0;
    lbl_805A0434[0x33CC] = 0;
    lbl_805A0434[0x33CD] = 1;
    fn_80146FCC(11);
    return 0;
}
