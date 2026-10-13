/* Power algorithm adapted from the repository's OpenRVL/src/stl/e_pow.c.
 * Copyright (C) 2004 by Sun Microsystems, Inc. All rights reserved.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Brawl-specific constants, error handling, and entry points follow the
 * original Runtime.PPCEABI.H assembly. Shared data remains externally owned.
 */
struct DoubleWords {
    int high;
    int low;
};
#define HI(x) (((struct DoubleWords*)&(x))->high)
#define LO(x) (((struct DoubleWords*)&(x))->low)

extern int lbl_805A12E0[2];
extern double lbl_805A1300;
extern unsigned char lbl_8059FF68[];
extern const double lbl_805A4DE8, lbl_805A4DF0, lbl_805A4DF8;
extern const double lbl_805A4E00, lbl_805A4E08;
extern const double lbl_805A4E18, lbl_805A4E20, lbl_805A4E28;
extern const double lbl_805A4E30, lbl_805A4E38, lbl_805A4E40;
extern const double lbl_805A4E48, lbl_805A4E50, lbl_805A4E58;
extern const double lbl_805A4E60, lbl_805A4E68, lbl_805A4E70;
extern const double lbl_805A4E78, lbl_805A4E80, lbl_805A4E88;
extern const double lbl_805A4E90, lbl_805A4E98, lbl_805A4EA0;
extern const double lbl_805A4EA8, lbl_805A4EB0, lbl_805A4EB8;
extern const double lbl_805A4EC0, lbl_805A4EC8, lbl_805A4ED0;
extern const double lbl_805A4ED8, lbl_805A4EE0, lbl_805A4EE8;
extern const double lbl_805A4EF0, lbl_805A4EF8, lbl_805A4F00;
extern const double lbl_805A4F08, lbl_805A4F10, lbl_805A4F18;
extern double fn_803FD650(double);
extern double fn_80400D94(double);
extern double fn_803FC9BC(double, int);

/* Base-ten logarithm with a normalized binary exponent and split log10(2). */
double fn_803FD904(double x) {
    double y, z;
    int k, i, hx;
    unsigned int lx;
    hx = HI(x);
    lx = LO(x);
    k = 0;
    if (hx < 0x00100000) {
        if (((hx & 0x7fffffff) | lx) == 0) {
            lbl_805A12E0[0] = 33;
            return lbl_805A4DE8 / lbl_805A1300;
        }
        if (hx < 0) {
            lbl_805A12E0[0] = 33;
            return (x - x) / lbl_805A1300;
        }
        k -= 54;
        x *= lbl_805A4DF0;
        hx = HI(x);
    }
    if (hx >= 0x7ff00000) {
        return x + x;
    }
    k += (hx >> 20) - 0x3ff;
    i = (unsigned int)k >> 31;
    hx = (hx & 0x000fffff) | ((0x3ff - i) << 20);
    y = k + i;
    HI(x) = hx;
    z = lbl_805A4DF8 * y + lbl_805A4E00 * fn_803FD650(x);
    return z + lbl_805A4E08 * y;
}

#define one lbl_805A4E18
#define zero lbl_805A4E20
#define overflow_value lbl_805A4E28
#define half lbl_805A4E30
#define third lbl_805A4E38
#define quarter lbl_805A4E40
#define ivln2_h lbl_805A4E48
#define ivln2_l lbl_805A4E50
#define ivln2 lbl_805A4E58
#define two53 lbl_805A4E60
#define L1 lbl_805A4E68
#define L2 lbl_805A4E70
#define L3 lbl_805A4E78
#define L4 lbl_805A4E80
#define L5 lbl_805A4E88
#define L6 lbl_805A4E90
/* The split logarithm uses the exact binary64 value 3.0. */
#define three 3.0
#define cp_h lbl_805A4EA0
#define cp_l lbl_805A4EA8
#define cp lbl_805A4EB0
#define negative_one lbl_805A4EB8
#define huge lbl_805A4EC0
#define ovt lbl_805A4EC8
#define tiny lbl_805A4ED0
#define lg2_h lbl_805A4ED8
#define lg2 lbl_805A4EE0
#define lg2_l lbl_805A4EE8
#define P1 lbl_805A4EF0
#define P2 lbl_805A4EF8
#define P3 lbl_805A4F00
#define P4 lbl_805A4F08
#define P5 lbl_805A4F10
#define two lbl_805A4F18
static const double base_points[2] = {1.0, 1.5};
static const double high_parts[2] = {0.0, 5.84962487220764160156e-01};
static const double low_parts[2] = {0.0, 1.35003920212974897128e-08};
#define bp(k) base_points[k]
#define dp_h(k) high_parts[k]
#define dp_l(k) low_parts[k]

/* Split log2 and exponentiation preserve precision around integer powers. */
double fn_803FDA18(double x, double y) {
    double z, ax, z_h, z_l, p_h, p_l;
    double y1, t1, t2, r, s, t, u, v, w;
    int i, j, k, yisint, n;
    int hx, hy, ix, iy;
    unsigned int lx, ly;
    hx = HI(x); lx = LO(x);
    hy = HI(y); ly = LO(y);
    ix = hx & 0x7fffffff; iy = hy & 0x7fffffff;
    if ((iy | ly) == 0) return one;
    if (ix > 0x7ff00000 || (ix == 0x7ff00000 && lx != 0) ||
        iy > 0x7ff00000 || (iy == 0x7ff00000 && ly != 0)) return x + y;
    yisint = 0;
    if (hx < 0) {
        if (iy >= 0x43400000) yisint = 2;
        else if (iy >= 0x3ff00000) {
            k = (iy >> 20) - 0x3ff;
            if (k > 20) {
                j = ly >> (52 - k);
                if ((unsigned int)(j << (52 - k)) == ly) yisint = 2 - (j & 1);
            } else if (ly == 0) {
                j = iy >> (20 - k);
                if ((j << (20 - k)) == iy) yisint = 2 - (j & 1);
            }
        }
    }
    if (ly == 0) {
        if (iy == 0x7ff00000) {
            if (((ix - 0x3ff00000) | lx) == 0) return y - y;
            else if (ix >= 0x3ff00000) return hy >= 0 ? y : zero;
            else return hy < 0 ? -y : zero;
        }
        if (iy == 0x3ff00000) return hy < 0 ? one / x : x;
        if (hy == 0x40000000) return x * x;
        if (hy == 0x3fe00000 && hx >= 0) return fn_80400D94(x);
    }
    ax = __fabs(x);
    if (lx == 0) {
        if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
            z = ax;
            if (hy < 0) z = one / z;
            if (hx < 0) {
                if (((ix - 0x3ff00000) | yisint) == 0) z = (z - z) / (z - z);
                else if (yisint == 1) z = -z;
            }
            return z;
        }
    }
    if ((((hx >> 31) + 1) | yisint) == 0) {
        lbl_805A12E0[0] = 33;
        return *(float*)lbl_8059FF68;
    }
    if (iy > 0x41e00000) {
        if (iy > 0x43f00000) {
            if (ix <= 0x3fefffff) return hy < 0 ? overflow_value : zero;
            if (ix >= 0x3ff00000) return hy > 0 ? overflow_value : zero;
        }
        if (ix < 0x3fefffff) return hy < 0 ? overflow_value : zero;
        if (ix > 0x3ff00000) return hy > 0 ? overflow_value : zero;
        t = x - one;
        w = (t * t) * (half - t * (third - quarter * t));
        u = ivln2_h * t;
        v = ivln2_l * t - ivln2 * w;
        t1 = u + v;
        LO(t1) = 0;
        t2 = v - (t1 - u);
    } else {
        double ss, s2, s_h, s_l, t_h, t_l;
        n = 0;
        if (ix < 0x00100000) {
            ax *= two53; n -= 53; ix = HI(ax);
        }
        n += (ix >> 20) - 0x3ff;
        j = ix & 0x000fffff;
        ix = j | 0x3ff00000;
        if (j <= 0x3988e) k = 0;
        else if (j < 0xbb67a) k = 1;
        else { k = 0; n += 1; ix -= 0x00100000; }
        HI(ax) = ix;
        u = ax - bp(k);
        v = one / (ax + bp(k));
        ss = u * v;
        s_h = ss;
        LO(s_h) = 0;
        t_h = zero;
        HI(t_h) = ((ix >> 1) | 0x20000000) + 0x00080000 + (k << 18);
        t_l = ax - (t_h - bp(k));
        s_l = v * ((u - s_h * t_h) - s_h * t_l);
        s2 = ss * ss;
        r = s2 * s2 * (L1 + s2 * (L2 + s2 * (L3 + s2 * (L4 + s2 * (L5 + L6 * s2)))));
        r += s_l * (s_h + ss);
        s2 = s_h * s_h;
        t_h = three + s2 + r;
        LO(t_h) = 0;
        t_l = r - ((t_h - three) - s2);
        u = s_h * t_h;
        v = s_l * t_h + t_l * ss;
        p_h = u + v;
        LO(p_h) = 0;
        p_l = v - (p_h - u);
        z_h = cp_h * p_h;
        z_l = cp_l * p_h + cp * p_l + dp_l(k);
        t = (double)n;
        t1 = ((z_h + z_l) + dp_h(k)) + t;
        LO(t1) = 0;
        t2 = z_l - (((t1 - t) - dp_h(k)) - z_h);
    }
    s = one;
    if ((((hx >> 31) + 1) | (yisint - 1)) == 0) s = negative_one;
    y1 = y;
    LO(y1) = 0;
    p_l = t1 * (y - y1) + y * t2;
    p_h = y1 * t1;
    z = p_l + p_h;
    j = HI(z); i = LO(z);
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0) return huge * s * huge;
        if (ovt + p_l > z - p_h) return huge * s * huge;
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - (int)0xc090cc00) | i) != 0) return tiny * s * tiny;
        if (p_l <= z - p_h) return tiny * s * tiny;
    }
    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    n = 0;
    if (i > 0x3fe00000) {
        n = j + (0x00100000 >> (k + 1));
        k = ((n & 0x7fffffff) >> 20) - 0x3ff;
        t = zero;
        HI(t) = n & ~(0x000fffff >> k);
        n = ((n & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0) n = -n;
        p_h -= t;
    }
    t = p_l + p_h;
    LO(t) = 0;
    u = lg2_h * t;
    v = (p_l - (t - p_h)) * lg2 + lg2_l * t;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (P1 + t * (P2 + t * (P3 + t * (P4 + P5 * t))));
    r = (z * t1) / (t1 - two) - (w + z * w);
    z = one - (r - z);
    j = HI(z);
    j += n << 20;
    if ((j >> 20) <= 0) z = fn_803FC9BC(z, n);
    else HI(z) += n << 20;
    return s * z;
}
