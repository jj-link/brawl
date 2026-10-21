typedef unsigned char u8;

class ntFriendInfo;

extern "C" {
    void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
}

#pragma force_active on
extern "C" u8 fn_800D26A8(ntFriendInfo* arg0) {
    return *(u8*)((char*)(*getInstance__12ntFriendInfoFv(arg0)) + 0x52A);
}
