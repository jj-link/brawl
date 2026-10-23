#pragma force_active on
class ntFriendInfo;

extern "C" void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
extern "C" void* memset(void* p, int c, unsigned int n);

extern "C" void* fn_800D2580(ntFriendInfo* arg0, void* arg1) {
    unsigned char* dst;
    unsigned char* src;
    int i;
    int a;
    int b;

    src = (unsigned char*)((char*)(*getInstance__12ntFriendInfoFv(arg0)) + 0x4F0);
    dst = (unsigned char*)arg1;
    i = 5;
    memset(arg1, 0, 12);
    goto cond;

body:
    int c = (dst[0] = src[0]) | (dst[1] = src[1]);
    src += 2;
    dst += 2;
    if (c == 0) {
        goto done;
    }

cond:
    i -= 1;
    if (i >= 0) {
        goto body;
    }

done:
    return arg1;
}
