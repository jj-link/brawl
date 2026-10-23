#pragma force_active on

struct ntFriendInfo;

struct FriendData {
    unsigned char pad[0x450];
    unsigned char names[1][0x28];
};

extern "C" void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
extern "C" void* memset(void* dst, int c, unsigned int n);

extern "C" void* fn_800D2A30(ntFriendInfo* self, int index, unsigned char* dst) {
    void** inst = getInstance__12ntFriendInfoFv(self);
    unsigned char* out = dst;
    unsigned char* src = ((FriendData*)*inst)->names[index];
    int i = 0x14;

    memset(dst, 0, 0x2A);
    while (--i >= 0) {
        unsigned int b;
        unsigned int a = src[0];
        out[0] = a;
        b = src[1];
        src += 2;
        a |= b;
        out[1] = b;
        out += 2;
        if (a == 0) {
            break;
        }
    }
    return dst;
}
