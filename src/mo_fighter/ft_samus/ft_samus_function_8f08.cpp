#pragma force_active on
extern "C" {
void *fn_94_8E1C(void *p, int n);

void *fn_94_8F08(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x4c0;
    case 2:
        return fn_94_8E1C(p, n);
    default:
        return fn_94_8E1C(p, n);
    }
}
}
