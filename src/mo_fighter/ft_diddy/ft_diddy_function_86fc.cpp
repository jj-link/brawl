#pragma force_active on
extern "C" void *fn_115_8610(void *p, int n);

extern "C" void *fn_115_86FC(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x4c8;
    case 2:
        return fn_115_8610(p, n);
    default:
        return fn_115_8610(p, n);
    }
}
