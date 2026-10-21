#pragma force_active on
typedef unsigned long long u64;

extern "C" void** getInstance__12ntFriendInfoFv();
extern "C" void* memcpy(void*, const void*, unsigned int);

extern "C" u64 fn_800D2C10() {
    u64 result;
    void** pp = getInstance__12ntFriendInfoFv();
    memcpy(&result, (char*)(*pp) + 0x579, 8);
    return result;
}
