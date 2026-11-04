#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" void** getInstance__12ntFriendInfoFv(void* self);
extern "C" void fn_8014CB1C(void* a, int b);
extern "C" unsigned char g_Network[];

extern "C" void fn_800D2520(void* arg0, void* arg1) {
    unsigned char* obj = (unsigned char*)*getInstance__12ntFriendInfoFv(arg0);
    memcpy(obj + 0x52B, arg1, 0x4C);
    unsigned char* net = *(unsigned char**)(g_Network + 0x30);
    net[0x33F4] = 1;
    void** inst = getInstance__12ntFriendInfoFv(net);
    fn_8014CB1C(inst, 1);
}
