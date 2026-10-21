#pragma force_active on
extern int fn_801DD964(int a, int b, int c);

int fn_801DDC4C(int a, int b)
{
    unsigned int v = *(unsigned int *)(a + 0x1c);

    if (v > 3 || v < 3) {
        return 0;
    }

    return fn_801DD964(a, b, 1);
}
