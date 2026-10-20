#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
void* fn_27_1BBF64(u8* self, s32 idx) {
    s32 n = (*(s32*)(self + 0x18) >> 27) + idx;
    if (n >= 8) {
        n -= 8;
    }
    return self + 0x1c + n * 12;
}
}
