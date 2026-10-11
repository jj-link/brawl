/* Adapted from repository OpenRVL/src/stl/k_sin.c and k_tan.c.
 * Copyright (C) 1993, 2004 Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Constants retain their original runtime ownership.
 */
#define HI(x) (((int*)&(x))[0])
#define LO(x) (((int*)&(x))[1])

extern const double lbl_805A5008, lbl_805A5010, lbl_805A5018;
extern const double lbl_805A5020, lbl_805A5028, lbl_805A5030, lbl_805A5038;
extern const double lbl_805A5040, lbl_805A5048, lbl_805A5050, lbl_805A5058;
extern const double lbl_805A5060, lbl_805A5068;
extern const double lbl_80420368[13];

/* Sine on [-pi/4, pi/4], with an optional low-order input tail. */
double fn_803FFE14(double x, double y, int iy) {
    double z, r, v;
    int ix;
    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0) return x;
    }
    z = x * x;
    v = z * x;
    r = lbl_805A5008 + z * (lbl_805A5010 + z * (lbl_805A5018 + z * (lbl_805A5020 + lbl_805A5028 * z)));
    if (iy == 0) return x + v * (lbl_805A5030 + z * r);
    return x - ((z * (lbl_805A5038 * y - v * r) - y) - lbl_805A5030 * v);
}

/* Tangent on [-pi/4, pi/4]; iy=-1 selects the negative reciprocal. */
double fn_803FFED4(double x, double y, int iy) {
    double z, r, v, w, s;
    int ix, hx;
    hx = HI(x);
    ix = hx & 0x7fffffff;
    if (ix < 0x3e300000) {
        if ((int)x == 0) {
            if (((ix | LO(x)) | (iy + 1)) == 0) {
                return lbl_805A5040 / __fabs(x);
            } else {
                if (iy == 1) return x;
                return lbl_805A5048 / x;
            }
        }
    }
    if (ix >= 0x3fe59428) {
        if (hx < 0) {
            x = -x;
            y = -y;
        }
        z = lbl_805A5050 - x;
        w = lbl_805A5058 - y;
        x = z + w;
        y = lbl_805A5060;
    }
    z = x * x;
    w = z * z;
    r = lbl_80420368[1] + w * (lbl_80420368[3] + w * (lbl_80420368[5] + w * (lbl_80420368[7] + w * (lbl_80420368[9] + w * lbl_80420368[11]))));
    v = z * (lbl_80420368[2] + w * (lbl_80420368[4] + w * (lbl_80420368[6] + w * (lbl_80420368[8] + w * (lbl_80420368[10] + w * lbl_80420368[12])))));
    s = z * x;
    r = y + z * (s * (r + v) + y);
    r += lbl_80420368[0] * s;
    w = x + r;
    if (ix >= 0x3fe59428) {
        v = (double)iy;
        return (double)(1 - ((hx >> 30) & 2)) * (v - lbl_805A5068 * (x - (w * w / (w + v) - r)));
    }
    if (iy == 1) {
        return w;
    } else {
        double a, t;
        z = w;
        LO(z) = 0;
        v = r - (z - x);
        t = a = lbl_805A5048 / w;
        LO(t) = 0;
        s = lbl_805A5040 + t * z;
        return t + a * (s + t * v);
    }
}
