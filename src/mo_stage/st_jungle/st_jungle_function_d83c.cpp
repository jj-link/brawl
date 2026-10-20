#pragma force_active on
extern "C" int fn_51_D83C(void *p)
{
    unsigned int v = ((unsigned int *)p)[2];
    return (int)(((v >> 22) & 0xF) << 28) >> 29;
}
