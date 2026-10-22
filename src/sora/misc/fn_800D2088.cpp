#include <string.h>
#pragma force_active on

extern "C" void** getInstance__12ntFriendInfoFv();

extern "C" void* fn_800D2088(int arg0, int arg1, void* arg2) {
    void** inst = getInstance__12ntFriendInfoFv();
    memcpy(arg2, (char*)(*inst) + arg1 * 0x89 + 0x5BC, 0x4C);
    return arg2;
}
