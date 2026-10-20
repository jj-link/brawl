#pragma force_active on
extern "C" {
int fn_48_B834(int *p)
{
    int v = p[2] << 14;
    return (v & (int)0xFF000000) >> 25;
}
}
