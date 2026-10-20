#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1C53E8(void* self, s32 idx) {
    u8* p = (u8*)self;
    s32 n = (*(s32*)(p + 0x18) >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return p + 0x1c + n * 12;
}
