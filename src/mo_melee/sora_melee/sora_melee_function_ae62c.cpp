#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_27_AE62C(void *p)
{
    u32 w = ((u32 *)p)[2];
    return ((int)(((w << 2) | (w >> 30)) & 0xE0000000)) >> 30;
}
}
