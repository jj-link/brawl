#pragma force_active on
extern "C" {
void fn_27_1D53C8(void *a, int b, int c);

void fn_27_111870(unsigned char *p)
{
    if (p[0xa] == 1) {
        fn_27_1D53C8(*(unsigned char **)p + 0x9e8, 0, 0);
    }
}
}
