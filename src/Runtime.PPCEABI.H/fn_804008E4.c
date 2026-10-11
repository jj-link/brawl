/*
 * Adapted from the repository's OpenRVL s_modf.c and s_sin.c.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 */
extern const double lbl_805A50F8;
extern int fn_803FE260(double value, double* remainder);
extern double fn_803FE5F8(double value, double tail);
extern double fn_803FFE14(double value, double tail, int tail_present);

/* Preserve the original signed-zero behavior, including nonfinite inputs. */
double fn_804008E4(double x, double* integer) {
    int high, low, exponent;
    unsigned int mask;
    high = ((int*)&x)[0];
    low = ((int*)&x)[1];
    exponent = ((high >> 20) & 0x7ff) - 0x3ff;
    if (exponent < 20) {
        if (exponent < 0) {
            ((int*)integer)[0] = high & 0x80000000;
            ((int*)integer)[1] = 0;
            return x;
        } else {
            mask = 0x000fffff >> exponent;
            if (((high & mask) | low) == 0) {
                *integer = x;
                ((int*)&x)[0] &= 0x80000000;
                ((int*)&x)[1] = 0;
                return x;
            } else {
                ((int*)integer)[0] = high & ~mask;
                ((int*)integer)[1] = 0;
                return x - *integer;
            }
        }
    } else if (exponent > 51) {
        *integer = x;
        ((int*)&x)[0] &= 0x80000000;
        ((int*)&x)[1] = 0;
        return x;
    } else {
        mask = 0xffffffffu >> (exponent - 20);
        if ((low & mask) == 0) {
            *integer = x;
            ((int*)&x)[0] &= 0x80000000;
            ((int*)&x)[1] = 0;
            return x;
        } else {
            ((int*)integer)[0] = high;
            ((int*)integer)[1] = low & ~mask;
            return x - *integer;
        }
    }
}

double sin(double value) {
    double remainder[2];
    double zero = lbl_805A50F8;
    int magnitude = ((int*)&value)[0] & 0x7fffffff;
    int quadrant;

    if (magnitude <= 0x3fe921fb) {
        return fn_803FFE14(value, zero, 0);
    } else if (magnitude >= 0x7ff00000) {
        return value - value;
    } else {
        quadrant = fn_803FE260(value, remainder);
        switch (quadrant & 3) {
        case 0:
            return fn_803FFE14(remainder[0], remainder[1], 1);
        case 1:
            return fn_803FE5F8(remainder[0], remainder[1]);
        case 2:
            return -fn_803FFE14(remainder[0], remainder[1], 1);
        default:
            return -fn_803FE5F8(remainder[0], remainder[1]);
        }
    }
}
