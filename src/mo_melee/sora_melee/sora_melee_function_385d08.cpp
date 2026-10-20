#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_27_385D08(void* obj, int idx)
{
    u8* p = (u8*)obj;
    int i = (*(int*)(p + 8) >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return p + i * 20 + 12;
}
}
