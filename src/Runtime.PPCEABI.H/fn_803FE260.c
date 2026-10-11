/*
 * Adapted from the repository's OpenRVL e_rem_pio2.c and k_cos.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 */
extern const int lbl_80420190[66];
extern const int lbl_80420298[32];
extern const double lbl_805A4F28, lbl_805A4F30, lbl_805A4F38;
extern const double lbl_805A4F40, lbl_805A4F48, lbl_805A4F50;
extern const double lbl_805A4F58, lbl_805A4F60, lbl_805A4F68;
extern const double lbl_805A4F70, lbl_805A4F80, lbl_805A4F88;
extern const double lbl_805A4F90, lbl_805A4F98, lbl_805A4FA0;
extern const double lbl_805A4FA8, lbl_805A4FB0, lbl_805A4FB8;
extern const double lbl_805A4FC0;
extern int fn_803FE708(double* pieces, double* remainder, int exponent,
                      int count, int precision, const int* two_over_pi);

typedef union DoubleBits {
    double value;
    int words[2];
} DoubleBits;

int fn_803FE260(double x, double* y) {
    struct {
        DoubleBits z;
        double pieces[3];
    } work;
    double w, t, r, fn;
    int e0, i, j, nx, n, ix, hx;
    double* end;

    hx = ((int*)&x)[0];
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        y[0] = x;
        y[1] = lbl_805A4F28;
        return 0;
    }
    if (ix < 0x4002d97c) {
        double small;
        if (hx > 0) {
            small = work.z.value = x - lbl_805A4F30;
            if (ix != 0x3ff921fb) {
                y[0] = small - lbl_805A4F38;
                y[1] = (small - y[0]) - lbl_805A4F38;
            } else {
                small = work.z.value = small - lbl_805A4F40;
                y[0] = small - lbl_805A4F48;
                y[1] = (small - y[0]) - lbl_805A4F48;
            }
            return 1;
        } else {
            small = work.z.value = lbl_805A4F30 + x;
            if (ix != 0x3ff921fb) {
                y[0] = lbl_805A4F38 + small;
                y[1] = (small - y[0]) + lbl_805A4F38;
            } else {
                small = work.z.value = small + lbl_805A4F40;
                y[0] = lbl_805A4F48 + small;
                y[1] = (small - y[0]) + lbl_805A4F48;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb) {
        t = __fabs(x);
        n = (int)(lbl_805A4F50 + lbl_805A4F58 * t);
        fn = (double)n;
        r = t - lbl_805A4F30 * fn;
        w = lbl_805A4F38 * fn;
        if (n < 32 && ix != lbl_80420298[n - 1]) {
            y[0] = r - w;
        } else {
            j = ix >> 20;
            y[0] = r - w;
            i = j - ((((int*)y)[0] >> 20) & 0x7ff);
            if (i > 16) {
                t = r;
                w = lbl_805A4F40 * fn;
                r = t - w;
                w = lbl_805A4F48 * fn - ((t - r) - w);
                y[0] = r - w;
                i = j - ((((int*)y)[0] >> 20) & 0x7ff);
                if (i > 49) {
                    t = r;
                    w = lbl_805A4F60 * fn;
                    r = t - w;
                    w = lbl_805A4F68 * fn - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0) {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        return n;
    }
    if (ix >= 0x7ff00000) {
        y[0] = y[1] = x - x;
        return 0;
    }
    work.z.words[1] = ((int*)&x)[1];
    e0 = (ix >> 20) - 1046;
    work.z.words[0] = ix - (e0 << 20);
    for (i = 0; i < 2; ++i) {
        work.pieces[i] = (double)(int)work.z.value;
        work.z.value = lbl_805A4F70 * (work.z.value - work.pieces[i]);
    }
    work.pieces[2] = work.z.value;
    nx = 3;
    end = work.pieces + nx;
    while (lbl_805A4F28 == end[-1]) {
        --end;
        --nx;
    }
    n = fn_803FE708(work.pieces, y, e0, nx, 2, lbl_80420190);
    if (hx < 0) {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}

double fn_803FE5F8(double x, double y) {
    double a, hz, z, r, qx;
    int ix = ((int*)&x)[0] & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0) return lbl_805A4F80;
    }
    z = x * x;
    r = z * (lbl_805A4F88 + z * (lbl_805A4F90 + z * (lbl_805A4F98 +
        z * (lbl_805A4FA0 + z * (lbl_805A4FA8 + lbl_805A4FB0 * z)))));
    if (ix < 0x3fd33333) {
        return lbl_805A4F80 - (lbl_805A4FB8 * z - (z * r - x * y));
    }
    if (ix > 0x3fe90000) {
        qx = lbl_805A4FC0;
    } else {
        ((int*)&qx)[0] = ix - 0x00200000;
        ((int*)&qx)[1] = 0;
    }
    hz = lbl_805A4FB8 * z - qx;
    a = lbl_805A4F80 - qx;
    return a - (hz - (z * r - x * y));
}
