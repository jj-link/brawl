#pragma force_active on
extern "C" {
void *fn_120_7A20(void *p, int n);

void *fn_120_7B0C(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x484;
    case 2:
        return fn_120_7A20(p, n);
    default:
        return fn_120_7A20(p, n);
    }
}
}
