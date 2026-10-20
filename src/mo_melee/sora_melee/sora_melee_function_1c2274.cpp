#pragma force_active on
typedef unsigned char u8;

extern "C" {
void* fn_27_1C2274(u8* self, int idx)
{
    int t = *(int*)(self + 0x18) >> 28;
    int i = t + idx;
    if (i >= 7) {
        i -= 7;
    }
    return self + i * 12 + 0x1c;
}
}
