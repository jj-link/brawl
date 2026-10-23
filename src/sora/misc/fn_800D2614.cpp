#pragma force_active on

extern "C" {
void** getInstance__12ntFriendInfoFv(void*);
void* memset(void*, int, unsigned int);

void* fn_800D2614(void* a, void* b) {
    unsigned char* base = (unsigned char*)*getInstance__12ntFriendInfoFv(a);
    unsigned char* dst = (unsigned char*)b;
    unsigned char* src = base + 0x4fa;
    int n = 20;

    memset(b, 0, 42);

    int u;
    int t;
    while (--n >= 0) {
        t = src[0];
        dst[0] = t;
        u = src[1];
        src += 2;
        t |= u;
        dst[1] = u;
        dst += 2;
        if (t == 0)
            break;
    }

    return b;
}
}
