/* Adapted from repository OpenRVL/src/stl/e_sqrt.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Brawl's error value and shared floating constants retain external ownership.
 */
#define HI(x) (((int*)&(x))[0])
#define LO(x) (((unsigned int*)&(x))[1])

extern int lbl_805A12E0[2];
extern const float lbl_8059FF68[];
extern const double lbl_805A5108;

/* Bit-by-bit square root of a double, including subnormal normalization. */
double fn_80400B48(double x) {
    double z;
    int sign = (int)0x80000000;
    unsigned int r, t1, s1, ix1, q1;
    int ix0, s0, q, m, t, i;

    ix0 = HI(x);
    ix1 = LO(x);
    if ((ix0 & 0x7ff00000) == 0x7ff00000) {
        lbl_805A12E0[0] = 33;
        return x * x + x;
    }
    if (ix0 <= 0) {
        if (((ix0 & ~sign) | ix1) == 0) {
            return x;
        } else if (ix0 < 0) {
            lbl_805A12E0[0] = 33;
            return lbl_8059FF68[0];
        }
    }
    m = ix0 >> 20;
    if (m == 0) {
        while (ix0 == 0) {
            m -= 21;
            ix0 |= ix1 >> 11;
            ix1 <<= 21;
        }
        for (i = 0; (ix0 & 0x00100000) == 0; i++) {
            ix0 <<= 1;
        }
        m -= i - 1;
        ix0 |= ix1 >> (32 - i);
        ix1 <<= i;
    }
    m -= 1023;
    ix0 = (ix0 & 0x000fffff) | 0x00100000;
    if (m & 1) {
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
    }
    m >>= 1;
    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    q = q1 = s0 = s1 = 0;
    r = 0x00200000;
    while (r != 0) {
        t = s0 + r;
        if (t <= ix0) {
            s0 = t + r;
            ix0 -= t;
            q += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }
    r = sign;
    while (r != 0) {
        t1 = s1 + r;
        t = s0;
        if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
            s1 = t1 + r;
            if (((t1 & sign) == sign) && (s1 & sign) == 0) {
                s0 += 1;
            }
            ix0 -= t;
            if (ix1 < t1) {
                ix0 -= 1;
            }
            ix1 -= t1;
            q1 += r;
        }
        ix0 += ix0 + ((ix1 & sign) >> 31);
        ix1 += ix1;
        r >>= 1;
    }
    /* The original runtime's rounding probes have both folded to one. */
    if ((ix0 | ix1) != 0) {
        z = lbl_805A5108;
        if (z >= lbl_805A5108) {
            z = lbl_805A5108;
            if (q1 == (unsigned int)0xffffffff) {
                q1 = 0;
                q += 1;
            } else if (z > lbl_805A5108) {
                if (q1 == (unsigned int)0xfffffffe) {
                    q += 1;
                }
                q1 += 2;
            } else {
                q1 += q1 & 1;
            }
        }
    }
    ix0 = (q >> 1) + 0x3fe00000;
    ix1 = q1 >> 1;
    if ((q & 1) == 1) {
        ix1 |= sign;
    }
    ix0 += m << 20;
    HI(z) = ix0;
    LO(z) = ix1;
    return z;
}
