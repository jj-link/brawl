#pragma force_active on
typedef int s32;

extern "C" char* fn_27_264928(char* p, s32 n)
{
    s32 v = *(s32*)(p + 8);
    s32 i = (v >> 30) + n;
    if (i >= 1) {
        i -= 1;
    }
    return p + i * 12 + 12;
}
