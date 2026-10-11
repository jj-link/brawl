/* Arctangent constants from OpenRVL/src/stl/s_atan.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 */
typedef unsigned int u32;

typedef union DoubleBits {
    double value;
    u32 words[2];
} DoubleBits;

static const double high[] = {
    4.63647609000806093515e-01, 7.85398163397448278999e-01,
    9.82793723247329054082e-01, 1.57079632679489655800e+00
};
static const double low[] = {
    2.26987774529616870924e-17, 3.06161699786838301793e-17,
    1.39033110312309984516e-17, 6.12323399573676603587e-17
};
static const double coefficient[] = {
    3.33333333333329318027e-01, -1.99999999998764832476e-01,
    1.42857142725034663711e-01, -1.11111104054623557880e-01,
    9.09088713343650656196e-02, -7.69187620504482999495e-02,
    6.66107313738753120669e-02, -5.83357013379057348645e-02,
    4.97687799461593236017e-02, -3.65315727442169155270e-02,
    1.62858201153657823623e-02
};
extern const double lbl_805A5078;
extern const double lbl_805A5080;
extern const double lbl_805A5088;
extern const double lbl_805A5090;
extern const double lbl_805A5098;
extern const double lbl_805A50A0;
extern const double lbl_805A50A8;


/* Reduce to one of four small intervals, then evaluate the alternating
   polynomial with even and odd coefficient chains. */
double fn_8040012C(double x) {
    int id, ix;
    int hx;
    DoubleBits bits;
    double w, s1, s2, z, magnitude;
    bits.value = x;
    hx = bits.words[0];
    ix = hx & 0x7fffffff;
    if (ix >= 0x44100000) {
        if (ix > 0x7ff00000 || (ix == 0x7ff00000 && bits.words[1] != 0)) {
            return bits.value + bits.value;
        }
        if (hx > 0) return high[3] + low[3];
        return -high[3] - low[3];
    }
    if (ix < 0x3fdc0000) {
        if (ix < 0x3e200000 && lbl_805A5078 + bits.value > lbl_805A5080) return bits.value;
        id = -1;
    } else {
        magnitude = __fabs(bits.value);
        if (ix < 0x3ff30000) {
            if (ix < 0x3fe60000) {
                id = 0;
                bits.value = (lbl_805A5088 * magnitude - lbl_805A5080) / (lbl_805A5088 + magnitude);
            } else {
                id = 1;
                bits.value = (magnitude - lbl_805A5080) / (lbl_805A5080 + magnitude);
            }
        } else if (ix < 0x40038000) {
            id = 2;
            bits.value = (magnitude - lbl_805A5090) / (lbl_805A5080 + lbl_805A5090 * magnitude);
        } else {
            id = 3;
            bits.value = lbl_805A5098 / magnitude;
        }
    }
    {
        z = bits.value * bits.value;
        w = z * z;
        s1 = z * (coefficient[0] + w * (coefficient[2] + w * (coefficient[4] + w * (coefficient[6] + w * (coefficient[8] + w * coefficient[10])))));
        s2 = w * (coefficient[1] + w * (coefficient[3] + w * (coefficient[5] + w * (coefficient[7] + w * coefficient[9]))));
        if (id < 0) return bits.value - bits.value * (s1 + s2);
        w = high[id] - ((bits.value * (s1 + s2) - low[id]) - bits.value);
        return hx < 0 ? -w : w;
    }
}

/* Clear fractional significand bits, carrying upward only for positive
   nonintegral values. The large addition preserves inexact exceptions. */
double fn_8040036C(double x) {
    int high;
    u32 low;
    int exponent;
    u32 mask, rounded;
    high = ((int*)&x)[0];
    low = ((u32*)&x)[1];
    exponent = ((high >> 20) & 0x7ff) - 1023;
    if (exponent < 20) {
        if (exponent < 0) {
            if (lbl_805A50A0 + x > lbl_805A50A8) {
                if (high < 0) { high = 0x80000000u; low = 0; }
                else if ((high | low) != 0) { high = 0x3ff00000; low = 0; }
            }
        } else {
            mask = 0x000fffff >> exponent;
            if (((high & mask) | low) == 0) return x;
            if (lbl_805A50A0 + x > lbl_805A50A8) {
                if (high > 0) high += 0x00100000 >> exponent;
                high &= ~mask;
                low = 0;
            }
        }
    } else if (exponent > 51) {
        if (exponent == 1024) return x + x;
        return x;
    } else {
        mask = 0xffffffffu >> (exponent - 20);
        if ((low & mask) == 0) return x;
        if (lbl_805A50A0 + x > lbl_805A50A8) {
            if (high > 0) {
                if (exponent == 20) ++high;
                else {
                    rounded = low + (1u << (52 - exponent));
                    if (rounded < low) ++high;
                    low = rounded;
                }
            }
            low &= ~mask;
        }
    }
    ((int*)&x)[0] = high;
    ((u32*)&x)[1] = low;
    return x;
}
