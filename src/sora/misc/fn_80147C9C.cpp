#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#pragma force_active on

extern "C" void fn_8014C964(ntFriendInfo*);
extern "C" void fn_8014C970(ntFriendInfo*);
extern "C" void fn_8014CB1C(ntFriendInfo*, int);
extern "C" int fn_803368A0(char*, int);
extern char lbl_8045F7A8[];
extern void* lbl_805A0434;

extern "C" unsigned int fn_80147C9C(unsigned char* self, int arg) {
    char* base = lbl_8045F7A8;
    fn_8014C964(ntFriendInfo::getInstance());
    char* info = (char*)ntFriendInfo::getInstance()->getFriendInfo();
    unsigned char* order = (unsigned char*)info + 0x27c1;
    int count = fn_803368A0(info + 0x50, 0x40);
    *(int*)((char*)lbl_805A0434 + 0x3408) = count;
    unsigned int result = 0;
    int i;
    for (i = 0; i < 64; i++) {
        if (order[i] == 0) {
            result = 1;
            order[i] = arg + 1;
            break;
        }
    }
    if (result == 1)
        fn_8014CB1C(ntFriendInfo::getInstance(), 1);
    else
        netReport(base + 0x100);
    fn_8014C970(ntFriendInfo::getInstance());
    netReport(base + 0x130, i, count);
    for (int k = 0; k < 64; k++)
        netReport0(base + 0x168, k, order[k] - 1);
    unsigned char* slots;
    int j;
    for (j = 0; j < 64; j++) {
        if ((self + j)[0x12] == 0)
            break;
    }
    if (j == 64) {
        netReport(base + 0x180);
        return 0;
    }
    slots = self + 0x52;
    (self + j)[0x12] = 3;
    for (i = 0; i < 64; i++) {
        if (slots[i] == 0) {
            slots[i] = j + 1;
            break;
        }
    }
    return result;
}