#include <nt/nt_offline.h>
#include <ip/ip_switch.h>
#include <mu/wifi/mu_wifi_interface.h>

#pragma force_active on

extern unsigned char* lbl_805A0434;
extern int gUnk805a03d8;
extern char lbl_804603B8[];

extern "C" unsigned long long fn_8014FEB4();
extern "C" int fn_80336928(void*, int);
extern "C" int fn_803369C0();
extern "C" void fn_8014A3A0();
extern "C" void fn_801475A4(void*, int, int, int, int);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8014C180(void*);
extern "C" void fn_8014C26C(void*, int, int);
extern "C" void fn_8014C964(void*);
extern "C" void fn_8014C970(void*);
extern "C" void fn_8014CB1C(void*, int);
extern "C" void fn_803369F0(void*);
extern "C" void fn_80148210();
extern "C" void fn_80148280();
extern "C" void fn_801482C8();
extern "C" void fn_80339E98(int, void (*)(), int, void (*)(), int, void (*)(), int);

inline int checkState(int v) {
    int flag = 0;
    if (v >= 3 && v <= 6) {
        flag++;
    }
    return flag;
}

extern "C" void fn_8014A0F4() {
    if (lbl_805A0434[0x33f4]) {
        unsigned char* p = *(unsigned char**)ntFriendInfo::getInstance() + 0x4f0;
        unsigned long long v = fn_8014FEB4();

        p[0x32] = v >> 56;
        p[0x33] = v >> 48;
        p[0x34] = v >> 40;
        p[0x35] = v >> 32;
        p[0x36] = v >> 24;
        p[0x37] = v >> 16;
        p[0x38] = v >> 8;
        p[0x39] = v;

        int result = fn_80336928(p, 0x89);
        if (((unsigned int)(-result | result) >> 31) != 0) {
            lbl_805A0434[0x33f4] = 0;
            netReport(lbl_804603B8);
        }
    }

    if (*(int*)ipSwitch::getInstance() != 1) {
        for (int i = 0; i < 2; i++) {
            fn_8014A3A0();
        }

        if (lbl_805A0434[0x3410] && fn_803369C0()) {
            fn_801475A4(
                lbl_805A0434,
                *(signed char*)(lbl_805A0434 + 0x3420),
                *(int*)(lbl_805A0434 + 0x3418),
                *(int*)(lbl_805A0434 + 0x341c),
                0
            );
            lbl_805A0434[0x3410] = 0;

            if (lbl_805A0434[0x3412]) {
                if (checkState(gUnk805a03d8)) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x48, 6);
                    if (p) {
                        p = fn_8014C180(p);
                    }
                    if (p) {
                        fn_8014C26C(p, 6, 1);
                    }
                }
                lbl_805A0434[0x3412] = 0;
            }
        }

        if (lbl_805A0434[0x3411] && fn_803369C0()) {
            int index = *(signed char*)(lbl_805A0434 + 0x3421);
            char* info = (char*)ntFriendInfo::getInstance()->getFriendInfo();

            fn_8014C964(ntFriendInfo::getInstance());
            fn_803369F0(info + index * 12 + 0x50);
            *(index * 4 + info + 0x350) = 0;
            fn_8014CB1C(ntFriendInfo::getInstance(), 1);
            fn_8014C970(ntFriendInfo::getInstance());
            fn_80339E98(0, fn_80148210, 0, fn_80148280, 0, fn_801482C8, 0);
            lbl_805A0434[0x3411] = 0;

            if (lbl_805A0434[0x3412]) {
                if (checkState(gUnk805a03d8)) {
                    void* p = __nw__FUlQ25Heaps8HeapType(0x48, 6);
                    if (p) {
                        p = fn_8014C180(p);
                    }
                    if (p) {
                        fn_8014C26C(p, 6, 1);
                    }
                }
                lbl_805A0434[0x3412] = 0;
            }
        }
    }
}
