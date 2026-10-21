#include <types.h>
#include <string.h>
#pragma force_active on
struct FriendInfo;
extern "C" FriendInfo* getInstance__12ntFriendInfoFv();
extern "C" void fn_8014CB1C(void*, int);
extern "C" u8 fn_800C851C();
struct Copy160 { u8 bytes[160]; };
struct FriendData { u8 pad[0x450]; u8 names[4][40]; };
struct FriendInfo { FriendData* data; };
extern "C" void fn_800D2AD0(u8* self, const u8* src, int index) {
    u8* dst = getInstance__12ntFriendInfoFv()->data->names[index];
    int count = 20;
    memset(dst, 0, 40);
    while (--count >= 0) {
        u32 value = (dst[0] = src[0]) | (dst[1] = src[1]);
        src += 2;
        dst += 2;
        if (value == 0) break;
    }
    fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
    u8 slot = fn_800C851C();
    if (slot == 255) slot = 4;
    *(Copy160*)(self + slot * 0x218 + 0x1A8) = *(Copy160*)(getInstance__12ntFriendInfoFv()->data->names);
}
