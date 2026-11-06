#pragma force_active on

void fn_80265D48(int *arg0, signed char *arg1)
{
    int a = arg0[0];
    int flag = 0;
    int b = arg0[1];
    int c = arg0[8];
    int d = arg0[9];
    int ab = a + b;
    int ab2 = a - b;
    int cd = c + d;
    int cd2 = c - d;
    int v;
    int r;

    v = (ab + cd) >> 11;
    if (v < 0x80 && v > -0x81) {
        flag = 1;
    }
    if (flag != 0) {
        r = v;
    } else {
        if (v > 0) {
            r = 0x7f;
        } else {
            r = -0x80;
        }
    }
    arg1[0] = r;

    {
        int f = 0;
        v = (ab - cd) >> 11;
        if (v < 0x80 && v > -0x81) {
            f = 1;
        }
        if (f != 0) {
            r = v;
        } else {
            if (v > 0) {
                r = 0x7f;
            } else {
                r = -0x80;
            }
        }
        arg1[8] = r;
    }

    {
        int f = 0;
        v = (ab2 + cd2) >> 11;
        if (v < 0x80 && v > -0x81) {
            f = 1;
        }
        if (f != 0) {
            r = v;
        } else {
            if (v > 0) {
                r = 0x7f;
            } else {
                r = -0x80;
            }
        }
        arg1[1] = r;
    }

    {
        int f = 0;
        int w = (ab2 - cd2) >> 11;
        if (w < 0x80 && w > -0x81) {
            f = 1;
        }
        if (f != 0) {
            r = w;
        } else {
            if (w > 0) {
                r = 0x7f;
            } else {
                r = -0x80;
            }
        }
        arg1[9] = r;
    }
}
