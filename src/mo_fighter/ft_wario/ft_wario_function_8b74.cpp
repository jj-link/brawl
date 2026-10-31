#pragma force_active on
extern "C" void *fn_110_8A88(void *, int);

extern "C" void *fn_110_8B74(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x4d0;
    case 2:
        return fn_110_8A88(p, n);
    default:
        return fn_110_8A88(p, n);
    }
}
