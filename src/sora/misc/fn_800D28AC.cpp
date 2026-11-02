#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
extern int g_NtAIDBitmap;
extern "C" u8 fn_800C851C();
extern "C" void** getInstance__12ntFriendInfoFv();
extern "C" void* memset(void*, int, unsigned long);

extern "C" s16* fn_800D28AC(void* arg0, u32 arg1, int arg2, s16* arg3) {
    if (!(g_NtAIDBitmap & (1 << arg1))) {
        *arg3 = 0;
        return arg3;
    }
    u8* entry = (u8*)arg0 + arg1 * 0x218;
    u8 local = fn_800C851C();
    if (local == 0xFF) local = 4;
    u8* base;
    if (arg1 == local) {
        base = (u8*)*getInstance__12ntFriendInfoFv() + 0x450;
    } else {
        base = entry + 0x1A8;
    }
    u8* dst = (u8*)arg3;
    u8* src = base + arg2 * 40;
    int count = 20;
    int c;
    memset(arg3, 0, 42);
    while (--count >= 0) {
        c = (dst[0] = src[0]) | (dst[1] = src[1]);
        src += 2;
        dst += 2;
        if (c == 0)
            break;
    }
    return arg3;
}