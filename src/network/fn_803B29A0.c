#pragma force_active on

void fn_803B29A0(unsigned char *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        p[i] = 0x2E;
    }
    for (i = 2; i < 11; i++) {
        p[i] = 0x20;
    }
}
