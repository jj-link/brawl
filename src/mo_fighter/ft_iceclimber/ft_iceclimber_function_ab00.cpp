#pragma force_active on
extern "C" {
void fn_27_132278(void *p, int x);

void fn_105_AB00(unsigned char *p, int x)
{
    if (p[0x1FE4C] == 0) {
        fn_27_132278(p, x);
    }
}
}
