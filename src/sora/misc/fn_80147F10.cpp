#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void fn_8014C964(ntFriendInfo*);
extern "C" void fn_8014C970(ntFriendInfo*);
extern "C" void fn_8014CB1C(ntFriendInfo*, int);
extern "C" int fn_803368A0(char*, int);
extern char lbl_8045F7A8[];
extern void* lbl_805A0434;

extern "C" unsigned int fn_80147F10(unsigned char* self, int arg, int flag) {
    char* base = lbl_8045F7A8;
    char* info = (char*)ntFriendInfo::getInstance()->getFriendInfo();
    unsigned char* order = (unsigned char*)info + 0x27c1;
    int count = fn_803368A0(info + 0x50, 0x40);
    *(int*)((char*)lbl_805A0434 + 0x3408) = count;
    unsigned int result = 0;
    fn_8014C964(ntFriendInfo::getInstance());
    int i;
    for (i = 0; i < 64; i++) {
        if (arg == order[i] - 1) {
            netReport(base + 0x1a4, arg, i);
            for (; i < 63; i++)
                order[i] = order[i + 1];
            result = 1;
            order[63] = 0;
            break;
        }
    }
    if (result == 1)
        fn_8014CB1C(ntFriendInfo::getInstance(), 1);
    else if (flag)
        netReport(base + 0x1cc, arg);
    fn_8014C970(ntFriendInfo::getInstance());
    netReport(base + 0x210, count);
    for (int k = 0; k < 64; k++)
        netReport0(base + 0x168, k, order[k] - 1);
    if (flag) {
        unsigned char* slots = self + 0x52;
        (self + arg)[0x12] = 0;
        for (int j = 0; j < 64; j++) {
            if (arg == slots[j] - 1) {
                for (; j < 63; j++)
                    slots[j] = slots[j + 1];
                slots[63] = 0;
                break;
            }
        }
    }
    return result;
}
