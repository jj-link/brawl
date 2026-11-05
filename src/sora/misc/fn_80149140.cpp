#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern char lbl_8045FFC4[];
extern void* lbl_805A0434;
extern float lbl_805A2B68;

extern "C" int fn_80149140() {
    u32 rounds = (*reinterpret_cast<u32**>(ntFriendInfo::getInstance()))[2];
    u32 wins = (*reinterpret_cast<u32**>(ntFriendInfo::getInstance()))[3];
    int percentage;
    if (rounds != 0) {
        percentage = (int)(lbl_805A2B68 * ((float)wins / (float)rounds));
        if (percentage > 100) {
            percentage = 100;
        }
    } else {
        percentage = 50;
    }
    netReport(lbl_8045FFC4, percentage, wins, rounds);
    *reinterpret_cast<int*>(static_cast<char*>(lbl_805A0434) + 0x3498) = percentage;
    return percentage;
}
