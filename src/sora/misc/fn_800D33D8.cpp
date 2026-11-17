#pragma force_active on
typedef unsigned char u8;
extern "C" u8 fn_800C851C(void);
extern "C" void* memset(void*, int, unsigned long);
extern int g_NtAIDBitmap;

struct NameRegion {
    u8 pad[0x1EA];
    u8 names[256][10];
};

extern "C" short* fn_800D33D8(char* a, unsigned int id, short* out, u8* outByte) {
    u8 k = *(u8*)(a + id * 8 + 0x4c);
    u8 j = *(u8*)(a + id * 8 + 0x4d);
    u8 idx;
    u8 v;
    int i;
    char* src;
    u8* dst;
    char* data;

    if (!(g_NtAIDBitmap & (1 << k)) || !((((u8*)a)[0xFC9] >> 7) & 1)) {
        if (out != 0) {
            *out = 0;
        }
        if (outByte != 0) {
            idx = fn_800C851C();
            if (idx == 0xFF) idx = 4;
            if (k == idx) {
                v = ((u8 (*)[0x218])a)[k][j + 0x278];
            } else {
                v = 0x78;
            }
            *outByte = v;
        }
    } else {
        char* base = a;
        base += k * 0x218;
        data = base + 0x70;
        if (out != 0) {
            src = (char*)((NameRegion*)data)->names[j];
            dst = (u8*)out;
            i = 5;
            memset(dst, 0, 12);
            while (--i >= 0) {
                int value = (dst[0] = src[0]) | (dst[1] = src[1]);
                src += 2;
                dst += 2;
                if (value == 0) break;
            }
        }
        if (outByte != 0) {
            idx = fn_800C851C();
            if (idx == 0xFF) idx = 4;
            if (k == idx) {
                v = *(u8*)(data + j + 0x208);
            } else {
                v = 0x78;
            }
            *outByte = v;
        }
    }
    return out;
}