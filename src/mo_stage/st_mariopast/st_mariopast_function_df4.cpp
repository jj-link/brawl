#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" const float lbl_48_rodata_0;

extern "C" void fn_48_DF4(char *self, u32 idx, float f)
{
    float *p = (float *)(self + 0x300) + (u8)idx;
    *p = *p - f;
    if (*p < lbl_48_rodata_0) {
        *p = lbl_48_rodata_0;
    }
    if (lbl_48_rodata_0 != *p) {
        return;
    }
    char *obj = *(char **)(self + 0x9c);
    if (obj == 0) {
        return;
    }
    u8 *cnt = (u8 *)self + idx;
    u32 c = cnt[0x308] + 1;
    cnt[0x308] = (u8)c;
    if ((u8)c == 3) {
        cnt[0x308] = 0;
    }
    *p = *(float *)(obj + 0x14);
}
