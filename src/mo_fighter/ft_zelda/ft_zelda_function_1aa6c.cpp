#pragma force_active on
extern "C" {
void *fn_104_979C(void *p, int n);

void *fn_104_1AA6C(void *p, int n)
{
    switch (n) {
    case 0:
        return p;
    case 1:
        return (char *)p + 0x488;
    case 2:
        return fn_104_979C(p, n);
    default:
        if (n >= 3) {
            return fn_104_979C(p, n);
        }
        return fn_104_979C(p, n);
    }
}
}
