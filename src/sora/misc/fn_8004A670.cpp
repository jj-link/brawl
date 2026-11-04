#pragma force_active on
#include <types.h>
#include <nt/network.h>
#include <ip/ip_network_producer.h>

struct Fn8004A670Flags {
    u8 a : 2;
    u8 b : 2;
    u8 c : 1;
    u8 d : 3;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* fn_8004AFB4(void* arg0, int arg1, unsigned long arg2);
void fn_801462B8(void* unused, s16 arg1);
void fn_8004A748(int arg0);
void fn_8004A798(void);
void fn_80146F88(u8 arg0, int arg1);

void* fn_8004A670(void* arg0) {
    u8* base = (u8*)arg0;
    Fn8004A670Flags* flags;
    void* p;
    u32 i;

    *(s32*)(base + 0x0) = 0;
    *(s32*)(base + 0x4) = 0;
    *(s32*)(base + 0x18) = 0;
    *(s32*)(base + 0x1C) = 0;
    flags = (Fn8004A670Flags*)(base + 0x24);
    flags->a = 0;
    flags->c = 0;
    base[0x25] = 0xFF;
    base[0x26] = 0xF;

    p = __nw__FUlQ25Heaps8HeapType(0x80, 1);
    if (p != 0) {
        p = fn_8004AFB4(p, 0xB, 0x4B000);
    }
    *(void**)(base + 0x18) = p;
    fn_801462B8(&g_Network, 4);
    fn_8004A748((int)&fn_8004A798);
    for (i = 0; i < 4; i++) {
        fn_80146F88((u8)i, 1);
    }
    *(ipNetworkProducer**)(base + 0x4) = ipNetworkProducer::getInstance();
    return arg0;
}
}
