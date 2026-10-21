#pragma force_active on
extern "C" int getFriendInfo__12ntFriendInfoFv(void* self) {
    if (*(unsigned char*)((char*)self + 9) == 0)
        return 0;
    return *(int*)self;
}
