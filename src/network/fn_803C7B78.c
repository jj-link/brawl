#pragma force_active on
typedef unsigned int u32;

extern u32 lbl_80563590[];

void fn_803C7B78(void)
{
    u32* p = &lbl_80563590[0];
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 0x28; j += 4) {
            p[j] = 0;
            p[j + 1] = 0;
            p[j + 2] = 0;
            p[j + 3] = 0;
        }
        p += 0x28;
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}
