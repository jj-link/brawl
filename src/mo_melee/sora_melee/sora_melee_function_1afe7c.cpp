#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1AFE7C(char* self, s32 idx)
{
    s32 n = (*(s32*)(self + 8) >> 22) + idx;
    if (n >= 0x11c) {
        n -= 0x11c;
    }
    return self + n * 4 + 0xc;
}
