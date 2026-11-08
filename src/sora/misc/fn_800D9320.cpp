#include <types.h>
#include <mt/mt_prng.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" u64 fn_803F1798(u64, u32);
extern mtRand lbl_805A0420;
extern char lbl_80459984[];

extern "C" int fn_800D9320(int a, int b, u64 mask) {
    int count = 0;
    int i = 0;
    do {
        if (mask & fn_803F1798(1ULL, i))
            count++;
        i++;
    } while (i < 35);
    if (count == 0) {
        netReport(lbl_80459984);
        count = 1;
    }
    int choice = (int)((float)count * lbl_805A0420.mtRand::randf());
    i = 0;
    do {
        if (mask & fn_803F1798(1ULL, i)) {
            if (--choice < 0)
                return i;
        }
        i++;
    } while (i < 35);
    return 0;
}