#pragma force_active on
extern "C" {
int fn_27_CE700(unsigned int *p)
{
    unsigned int r = (p[2] << 18) | (p[2] >> 14);
    return (int)(r & 0xFFC00000u) >> 23;
}
}
