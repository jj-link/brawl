#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_8014D0B4(void*, u32);
void* memset(void*, int, u32);
void* memcpy(void*, const void*, u32);

s32 fn_6_9904(void* self)
{
    u8* item = (u8*)self;
    if (*(u8*)(*(u8**)(item + 0x730) + 0x8C)) {
        u8* dst = item + 0x12C;
        u32 i = 0;
        while (i < *(u32*)(*(u8**)(item + 0x730) + 0x10) && (s32)i < 0x40) {
            memset(dst, 0, 0x16);
            memcpy(dst, (const void*)fn_8014D0B4(*(void**)(item + 0x730), i), 0x14);
            ++i;
            dst += 0x18;
        }
        *(u32*)(item + 0x72C) = i;
        return 5;
    }
    return *(s32*)(item + 0x124);
}
}
