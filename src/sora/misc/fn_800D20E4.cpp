#pragma force_active on
extern "C" void* getInstance__12ntFriendInfoFv();

extern "C" unsigned char fn_800D20E4(void* arg0, int arg1) {
    void* base = *(void**)getInstance__12ntFriendInfoFv();
    return *(unsigned char*)((unsigned char*)base + arg1 * 0x89 + 0x608);
}
