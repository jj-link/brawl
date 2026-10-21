#pragma force_active on
class ntFriendInfo;
extern "C" void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);

extern "C" unsigned char fn_800D204C(ntFriendInfo* self, int index) {
    return *(unsigned char*)((char*)(*getInstance__12ntFriendInfoFv(self)) + index * 0x89 + 0x5BB);
}
