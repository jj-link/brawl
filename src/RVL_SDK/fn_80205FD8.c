#pragma force_active on
typedef unsigned long u32;

static u32 bswap32(u32 x) {
    return (x >> 24) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | (x << 24);
}

u32 CXGetUncompressedSize(void* arg0) {
    u32 r = bswap32(*(u32*)arg0) >> 8;
    if (r == 0) {
        r = bswap32(*(u32*)((char*)arg0 + 4));
    }
    return r;
}
