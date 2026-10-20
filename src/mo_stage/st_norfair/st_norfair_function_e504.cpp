#pragma force_active on
extern "C" int fn_54_E504(int *p)
{
    int v = (p[2] << 8) & (int)0xF8000000;
    return v >> 28;
}
