#include <types.h>
#pragma force_active on
class ntFriendInfo;

extern "C" void** getInstance__12ntFriendInfoFv();

extern "C" {
u8 fn_800D2128(ntFriendInfo* arg0, s32 arg1) {
    char* p = (char*)*getInstance__12ntFriendInfoFv();
    return *(u8*)(p + arg1 * 4 + 0x353);
}
}
