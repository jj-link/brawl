#pragma force_active on
typedef unsigned char u8;

extern "C" {
void *fn_27_11BA60(u8 *self, int idx)
{
    int sh = *(int *)(self + 8) >> 28;
    int n = sh + idx;
    if (n >= 4) {
        n -= 4;
    }
    return self + n * 12 + 12;
}
}
