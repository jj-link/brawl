#pragma force_active on

static inline int clamp(int v)
{
    int flag = 0;
    if (v < 0x100 && v > -1) {
        flag = 1;
    }
    return flag ? v : (v < 0 ? 0 : 255);
}

void fn_802659C4(int *arg0, signed char *arg1, int arg2)
{
    int a = arg0[0] + 0x40000;
    int flag = 0;
    int b = arg0[1];
    int c = arg0[8];
    int d = arg0[9];
    int ab = a + b;
    int ab2 = a - b;
    int cd = c + d;
    int cd2 = c - d;

    arg1[0] = clamp((ab + cd) >> 11);
    arg1[arg2] = clamp((ab - cd) >> 11);
    arg1[1] = clamp((ab2 + cd2) >> 11);
    (arg1 + arg2)[1] = clamp((ab2 - cd2) >> 11);
}
