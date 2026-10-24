#pragma force_active on
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* memset(void*, int, unsigned);

struct Ctx {
    char pad[0x24];
    char* buf;
};

extern "C" int fn_8004B0F8(Ctx* ctx, void* src) {
    char* base = ctx->buf;
    memcpy(base + 0x18, src, 0x320);
    ctx->buf[0x70] = 0;
    char* p;
    int off;
    int count;
    count = 0;
    off = 0;
    do {
        p = ctx->buf + off;
        memset(p + 0xBC, 0, 0xC);
        p[0xC8] = 0x78;
        count++;
        off += 0x5C;
        p[0xC9] = 0x78;
    } while (count < 7);
    return 1;
}
