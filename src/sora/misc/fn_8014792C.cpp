#include <nt/nt_offline.h>
#include <mu/wifi/mu_wifi_interface.h>
#include <string.h>
#pragma force_active on
extern "C" {
int fn_803368A0(char*, int);
int fn_8035129C(void*);
int fn_803F6150(const void*, const void*, unsigned long);
void fn_80339E98(int, void (*)(int,int), int, void (*)(), int, void (*)(), int);
void fn_80148210(int,int);
void fn_80148280();
void fn_801482C8();
}
extern char lbl_8045F890[];
extern "C" void fn_8014792C(void* arg) {
    unsigned char* self = (unsigned char*)arg;
    unsigned char oldOrder[64];
    unsigned char newOrder[64];
    netReport(lbl_8045F890);
    char* info = (char*)ntFriendInfo::getInstance()->getFriendInfo();
    *(int*)(self + 0x3408) = fn_803368A0(info + 0x50, 64);
    memset(self + 0x12, 0, 64);
    char* entry = info + 0x50;
    for (int i = 0; i < 64; i++, entry += 12) {
        if (fn_8035129C(entry)) self[0x12 + i] = 1;
    }
    memcpy(oldOrder, info + 0x27c1, 64);
    for (int i = 0; i < 64; i++) {
        unsigned char n = oldOrder[i] - 1;
        if (n >= 64) oldOrder[i] = 0;
        else if (self[0x12 + n] == 0) oldOrder[i] = 0;
        else if (self[0x12 + n] != 1) oldOrder[i] = 0;
        else self[0x12 + n] = 2;
    }
    unsigned char count = 0;
    memset(newOrder, 0, 64);
    for (int i = 0; i < 64; i++) {
        if (oldOrder[i]) newOrder[count++] = oldOrder[i];
    }
    for (int i = 0; i < 64; i++) {
        if (self[0x12 + i] == 1) newOrder[count++] = i + 1;
    }
    if (fn_803F6150(newOrder, info + 0x27c1, 64)) memcpy(info + 0x27c1, newOrder, 64);
    memcpy(self + 0x52, info + 0x27c1, 64);
    fn_80339E98(0, fn_80148210, 0, fn_80148280, 0, fn_801482C8, 0);
}