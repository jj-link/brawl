#pragma force_active on
extern "C" {
void fn_70_8FD0(void *p)
{
    unsigned int *w = (unsigned int *)p;
    w[2] |= 0x02000000;
}
}
