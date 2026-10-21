#pragma force_active on
typedef unsigned int u32;

extern "C" void* getInstance__12ntFriendInfoFv();
extern "C" char* getFriendInfo__12ntFriendInfoFv(void*);
extern "C" void fn_80351794(u32*);

extern "C" void fn_8014B974(void* unused, int index) {
    fn_80351794((u32*)(getFriendInfo__12ntFriendInfoFv(getInstance__12ntFriendInfoFv()) + index * 0xC + 0x50));
}
