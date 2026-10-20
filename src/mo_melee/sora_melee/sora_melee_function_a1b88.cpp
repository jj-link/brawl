#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern "C" {
void* fn_27_A1B88(u8* p, s32 i) {
    s32 n = (*(s32*)(p + 8) >> 30) + i;
    if (n >= 1) {
        n -= 1;
    }
    return p + n + 9;
}
}
