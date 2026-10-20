#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
s32 fn_27_2AD39C(u8* self, s32 index, s32 value);

void fn_27_2AECF8(u8* self, s32 index, s32* out) {
    s32 r = fn_27_2AD39C(self, index - 1, -1);
    if (r >= 0) {
        *(s32*)(self + r * 12 + 12) = *out;
    }
}
}
