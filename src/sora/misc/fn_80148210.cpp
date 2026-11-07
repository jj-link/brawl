#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void fn_8014CB1C(void*, int);
extern int gUnk805a03d8;
extern char lbl_8045F9F8[];
extern char lbl_8045FA18[];

extern "C" void fn_80148210(int arg0, int arg1) {
    if (gUnk805a03d8 != 7 && arg0 == 0) {
        netReport(lbl_8045F9F8);
        if (arg1 != 0) {
            netReport(lbl_8045FA18);
            fn_8014CB1C(ntFriendInfo::getInstance(), 1);
        }
    }
}