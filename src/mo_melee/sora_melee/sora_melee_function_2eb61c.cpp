#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_2EB61C(void* self, s32 n) {
    u8* p = (u8*)self;
    s32 idx = (*(s32*)(p + 0x18) >> 29) + n;
    if (idx >= 3) {
        idx -= 3;
    }
    return p + 0x1c + idx * 12;
}
