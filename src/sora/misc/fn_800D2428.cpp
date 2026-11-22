#include <types.h>
#include <string.h>
#include <nt/nt_offline.h>
#include <nt/network.h>
#pragma force_active on
extern "C" void fn_8014CB1C(void*, int);
extern "C" void fn_800D2428(void* arg0, void* arg1) {
    u8* dst = (u8*)*(void**)ntFriendInfo::getInstance() + 0x4FA;
    u8* src = (u8*)arg1;
    int count = 0x14;
    memset(dst, 0, 0x28);
    while (--count >= 0) {
        u8 b;
        u8 a;
        a = src[0];
        b = src[1];
        src += 2;
        dst[0] = a;
        int value = a | (dst[1] = b);
        dst += 2;
        if (value == 0) break;
    }
    void* net = *(void**)((u8*)&g_Network + 0x30);
    *(u8*)((u8*)net + 0x33F4) = 1;
    fn_8014CB1C(ntFriendInfo::getInstance(), 1);
}