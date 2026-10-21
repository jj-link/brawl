#pragma force_active on
void fn_803B2968(unsigned char *p)
{
    int i;

    p[0] = 0x2E;
    for (i = 1; i < 11; i++) {
        p[i] = 0x20;
    }
}
