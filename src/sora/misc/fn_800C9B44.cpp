#include <mu/wifi/mu_wifi_interface.h>
#include <nt/network.h>
#include <nt/nt_offline.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_801473C4();
extern "C" void fn_80145D24(u32* p, u32 b, u32 c, u32 d, u32 e);
extern "C" void fn_800CF22C(void*);
extern "C" void** getInstance__12ntFriendInfoFv();

void muWifiInterfaceTask::connect(bool b) {
    char* self = (char*)this;
    int offset;
    Network* net;
    int i;

    self[0x48] = b;
    *(int*)(self + 0x44) = 1;
    *(int*)(self + 0x1048) = 0;
    *(int*)(self + 0x104C) = 0;

    fn_801473C4();

    int v = *(u8*)(self + 0xFCA);
    v &= 0xFFFFFFEF;
    *(u8*)(self + 0xFCA) = v;

    net = &g_Network;
    net->create(true);

    i = 0;
    offset = 0;
    for (; i < 64; i++) {
        u8* base = (u8*)*getInstance__12ntFriendInfoFv();
        u8* p = base + offset + 0x608;
        if (*p != 0) {
            *p = 2;
        }
        offset += 0x89;
    }

    fn_80145D24(*(u32**)((char*)net + 0x38), (u32)(self + 0x70), 0x218, 0x138, 4);
    fn_800CF22C(this);
}