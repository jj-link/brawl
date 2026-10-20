#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" s32 fn_27_2AD39C(void* self, s32 a, s32 b);

extern "C" void fn_27_2AEC10(u8* self, s32* src) {
    s32 idx = fn_27_2AD39C(self, -1, -1);
    if (idx >= 0) {
        *(s32*)(self + idx * 12 + 0xC) = *src;
    }
}
