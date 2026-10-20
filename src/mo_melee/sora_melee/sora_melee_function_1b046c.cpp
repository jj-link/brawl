#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1B046C(void* self, s32 idx) {
    u8* base = (u8*)self;
    s32 v = *(s32*)(base + 8);
    s32 i = (v >> 30) + idx;
    if (i >= 1) {
        i -= 1;
    }
    return base + i * 0x5c + 0xc;
}
