#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_66_A684(void* self, s32 n) {
    u8* base = (u8*)self;
    s32 idx = (*(s32*)(base + 8) >> 28) + n;
    if (idx >= 7) {
        idx -= 7;
    }
    return base + idx * 8 + 12;
}
