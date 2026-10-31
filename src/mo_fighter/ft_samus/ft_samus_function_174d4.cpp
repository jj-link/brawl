#pragma force_active on
extern "C" {
void *fn_94_8E1C(void *p, int n);

void *fn_94_174D4(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x490;
    case 2:
        return fn_94_8E1C(p, n);
    default:
        return fn_94_8E1C(p, n);
    }
}
}
