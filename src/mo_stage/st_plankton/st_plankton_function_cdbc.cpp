#pragma force_active on
extern "C" void fn_74_CDBC(char *r3, unsigned int r4, int r5)
{
    if (r4 >= 2) {
        return;
    }
    *(int *)(r3 + ((r4 << 2) & 0x3FC) + 4) = r5;
}
