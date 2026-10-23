#pragma force_active on
extern "C" {
void** getInstance__12ntFriendInfoFv(void* self);
void* memset(void* p, int c, unsigned int n);
}

extern "C" void* fn_800D1FAC(void* self, int index, void* dst) {
    void* ret = dst;
    unsigned char* out;
    unsigned char* src;
    int i;
    char* base = (char*)*getInstance__12ntFriendInfoFv(self);
    base = base + index * 0x89;
    src = (unsigned char*)(base + 0x58B);
    out = (unsigned char*)dst;
    i = 0x14;
    memset(dst, 0, 0x2A);
    goto check;
    for (;;) {
        int value = (out[0] = src[0]);
        value |= (out[1] = src[1]);
        src += 2;
        out += 2;
        if (value == 0) {
            break;
        }
    check:
        i = i - 1;
        if (i < 0) {
            break;
        }
    }
    return ret;
}
