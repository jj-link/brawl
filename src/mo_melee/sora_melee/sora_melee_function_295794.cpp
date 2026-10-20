#pragma force_active on
typedef signed int s32;

extern "C" char* fn_27_295794(char* self, s32 idx)
{
    s32 v = *(s32*)(self + 8);
    s32 i = (v >> 27) + idx;
    if (i >= 12) {
        i -= 12;
    }
    return self + (i << 4) + 12;
}
