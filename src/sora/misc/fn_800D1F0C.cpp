#include <nt/nt_offline.h>
#pragma force_active on

extern "C" void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
extern "C" void* memset(void* p, int c, unsigned int n);

extern "C" void* fn_800D1F0C(ntFriendInfo* arg0, int arg1, void* arg2) {
    unsigned char* dst;
    char* base = (char*)*getInstance__12ntFriendInfoFv(arg0) + arg1 * 0x89;
    unsigned char* src = (unsigned char*)(base + 0x581);
    dst = (unsigned char*)arg2;
    int i = 5;

    memset(dst, 0, 0xC);
    goto cond;

body:
    int value = (dst[0] = src[0]) | (dst[1] = src[1]);
    src += 2;
    dst += 2;
    if (value == 0) {
        goto done;
    }

cond:
    i -= 1;
    if (i >= 0) {
        goto body;
    }

done:
    return arg2;
}
