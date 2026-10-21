#include <types.h>
#include <cstring>
#pragma force_active on

class ntFriendInfo;

extern "C" {
    void* getInstance__12ntFriendInfoFv();
    void fn_8014CB1C(void*, int);
}

extern "C" void fn_800D2BC8(void* arg0, u64 value) {
    void* ptr = *(void**)getInstance__12ntFriendInfoFv();
    memcpy((char*)ptr + 0x579, &value, 8);
    fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
}
