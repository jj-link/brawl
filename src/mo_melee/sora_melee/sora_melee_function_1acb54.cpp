#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void* fn_27_1ACB54(u8* self, s32 idx) {
    s32 s = *(s32*)(self + 0x18) >> 28;
    s32 n = s + idx;
    if (n >= 6) {
        n -= 6;
    }
    return self + 0x1c + n * 16;
}
