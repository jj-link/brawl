/*
 * Adapted from repository OpenRVL s_frexp.c and s_ldexp.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 */
extern const double lbl_805A50C8;
extern const double lbl_805A50D0;
extern const double lbl_805A50D8;
extern const double lbl_805A50E0;
extern const double lbl_805A50E8;
extern const double lbl_805A50F0;
extern int fn_803F64E8(double value);
extern double fn_804004AC(double magnitude, double sign);

double fn_804006F0(double value, int* exponent) {
    int high = ((int*)&value)[0];
    int magnitude = high & 0x7fffffff;
    int low = ((int*)&value)[1];

    *exponent = 0;
    if (magnitude >= 0x7ff00000 || (magnitude | low) == 0) {
        return value;
    }
    if (magnitude < 0x00100000) {
        value *= lbl_805A50C8;
        high = ((int*)&value)[0];
        magnitude = high & 0x7fffffff;
        *exponent = -54;
    }
    *exponent += (magnitude >> 20) - 1022;
    high = (high & 0x800fffff) | 0x3fe00000;
    ((int*)&value)[0] = high;
    return value;
}

double fn_80400778(double value, int exponent) {
    int power;
    int high;
    int low;

    if (fn_803F64E8(value) <= 2 || lbl_805A50D0 == value) {
        return value;
    }
    high = ((int*)&value)[0];
    low = ((int*)&value)[1];
    power = (high & 0x7ff00000) >> 20;
    if (power == 0) {
        if ((low | (high & 0x7fffffff)) == 0) {
            return value;
        }
        value *= lbl_805A50D8;
        high = ((int*)&value)[0];
        power = ((high & 0x7ff00000) >> 20) - 54;
        if (exponent < -50000) {
            return lbl_805A50E0 * value;
        }
    }
    if (power == 0x7ff) {
        return value + value;
    }
    power += exponent;
    if (power > 0x7fe) {
        return lbl_805A50E8 * fn_804004AC(lbl_805A50E8, value);
    }
    if (power > 0) {
        ((int*)&value)[0] = (high & 0x800fffff) | (power << 20);
        return value;
    }
    if (power <= -54) {
        if (exponent > 50000) {
            return lbl_805A50E8 * fn_804004AC(lbl_805A50E8, value);
        } else {
            return lbl_805A50E0 * fn_804004AC(lbl_805A50E0, value);
        }
    }
    power += 54;
    ((int*)&value)[0] = (high & 0x800fffff) | (power << 20);
    return lbl_805A50F0 * value;
}
