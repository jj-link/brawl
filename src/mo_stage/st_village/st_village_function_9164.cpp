#pragma force_active on
extern "C" {
int fn_70_9164(unsigned int *p)
{
    return (int)((p[2] << 4) & 0xE0000000) >> 30;
}
}
