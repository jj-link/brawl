#pragma force_active on
typedef int s32;

extern "C" {
char* fn_27_1C2C30(char* self, s32 idx)
{
    s32 v = *(s32*)(self + 0x18);
    s32 i = (v >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return self + i * 12 + 0x1c;
}
}
