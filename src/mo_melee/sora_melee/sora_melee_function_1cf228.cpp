#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1CF228(void* self, s32 idx) {
    u8* p = (u8*)self;
    s32 v = *(s32*)(p + 0x18);
    s32 i = (v >> 26) + idx;
    if (i >= 0x10) {
        i -= 0x10;
    }
    return p + i * 12 + 0x1c;
}
