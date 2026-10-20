#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_27_24A7F8(void* p) {
    u8* obj = (u8*)p;
    u8* sub = *(u8**)(obj + 0x44);
    u32 kind = (sub[8] >> 2) & 0x3F;

    if (kind != 4) {
        if (kind != 2) {
            return;
        }
    }

    u8* r6 = *(u8**)(obj + 0xcc);
    s32 r5 = *(s32*)(obj + 0xe0);
    u32 r7 = *(u32*)(r6 + 0x1f0);
    if (r6[0x2d1] == 0) {
        r7 += *(u32*)(r6 + 0x49c);
    }

    *(s32*)(r6 + 0x264) = r5 / 60;
    *(u32*)(r6 + 0x268) = r7;
    *(u32*)(r6 + 0x26c) = 0;
    *(s32*)(r6 + 0x270) = *(s32*)(obj + 0xe0);
}
