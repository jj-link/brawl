#pragma force_active on
typedef unsigned char u8;

extern "C" {
void *fn_27_1BDD10(void *self, int idx)
{
    int n = *(int *)((u8 *)self + 0x18) >> 26;
    int i = n + idx;
    if (i >= 20) {
        i -= 20;
    }
    return (u8 *)self + 0x1c + i * 12;
}
}
