typedef unsigned int u32;
typedef union DoubleBits {
    double value;
    struct { int high; u32 low; } words;
} DoubleBits;

extern const double lbl_80420150[2];
extern double lbl_805A12F8;
extern int lbl_805A12E0;
extern const double lbl_805A4D68;
extern const double lbl_805A4D70;
extern const double lbl_805A4D78;
extern const double lbl_805A4D80;
extern const double lbl_805A4D88;
extern const double lbl_805A4D90;
extern const double lbl_805A4D98;
extern const double lbl_805A4DA0;
extern const double lbl_805A4DA8;
extern const double lbl_805A4DB0;
extern const double lbl_805A4DB8;
extern const double lbl_805A4DC0;
extern const double lbl_805A4DC8;
extern const double lbl_805A4DD0;
extern const double lbl_805A4DD8;
extern const double lbl_805A4DE0;

/* Fixed-point reduction of the two significands avoids rounding a quotient. */
double fn_803FD320(double x, double y) {
    int n, hx, hy, hz, ix, iy, sign, i;
    u32 lx, ly, lz;
    hx = ((int*)&x)[0];
    hy = ((int*)&y)[0];
    lx = ((u32*)&x)[1];
    ly = ((u32*)&y)[1];
    sign = hx & 0x80000000u;
    hx ^= sign;
    hy &= 0x7fffffff;
    if ((hy | ly) == 0 || hx >= 0x7ff00000 ||
        ((u32)hy | ((ly | (0u - ly)) >> 31)) > 0x7ff00000u) {
        double invalid = x * y;
        return invalid / invalid;
    }
    if (hx <= hy) {
        if (hx < hy || lx < ly) return x;
        if (lx == ly) return lbl_80420150[(u32)sign >> 31];
    }
    if (hx < 0x00100000) {
        if (hx == 0) {
            for (ix = -1043, i = lx; i > 0; i <<= 1) --ix;
        } else {
            for (ix = -1022, i = hx << 11; i > 0; i <<= 1) --ix;
        }
    } else ix = (hx >> 20) - 1023;
    if (hy < 0x00100000) {
        if (hy == 0) {
            for (iy = -1043, i = ly; i > 0; i <<= 1) --iy;
        } else {
            for (iy = -1022, i = hy << 11; i > 0; i <<= 1) --iy;
        }
    } else iy = (hy >> 20) - 1023;
    if (ix >= -1022) hx = 0x00100000 | (hx & 0x000fffff);
    else {
        n = -1022 - ix;
        if (n <= 31) {
            hx = ((u32)hx << n) | (lx >> (32 - n));
            lx <<= n;
        } else { hx = lx << (n - 32); lx = 0; }
    }
    if (iy >= -1022) hy = 0x00100000 | (hy & 0x000fffff);
    else {
        n = -1022 - iy;
        if (n <= 31) {
            hy = ((u32)hy << n) | (ly >> (32 - n));
            ly <<= n;
        } else { hy = ly << (n - 32); ly = 0; }
    }
    for (n = ix - iy; n != 0; --n) {
        hz = hx - hy;
        lz = lx - ly;
        if (lx < ly) --hz;
        if (hz < 0) {
            hx = (lx >> 31) + (hx << 1);
            lx += lx;
        } else {
            if ((hz | lz) == 0) return lbl_80420150[(u32)sign >> 31];
            hx = (lz >> 31) + (hz << 1);
            lx = lz << 1;
        }
    }
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly) --hz;
    if (hz >= 0) { hx = hz; lx = lz; }
    if ((hx | lx) == 0) return lbl_80420150[(u32)sign >> 31];
    while (hx < 0x00100000) {
        hx = (lx >> 31) + (hx << 1);
        lx += lx;
        --iy;
    }
    if (iy >= -1022) {
        hx = (hx - 0x00100000) | ((iy + 1023) << 20);
        ((u32*)&x)[1] = lx;
        ((int*)&x)[0] = hx | sign;
    } else {
        n = -1022 - iy;
        if (n <= 20) {
            lx = (lx >> n) | ((u32)hx << (32 - n));
            hx >>= n;
        } else if (n <= 31) {
            lx = ((u32)hx << (32 - n)) | (lx >> n);
            hx = sign;
        } else { lx = hx >> (n - 32); hx = sign; }
        ((u32*)&x)[1] = lx;
        ((int*)&x)[0] = hx | sign;
    }
    return x;
}

static inline double UnbiasExponent(double value, double bias) {
    return value - bias;
}

/* Range reduction to a neighborhood of one, followed by split-ln(2)
   compensation and an odd/even polynomial in f/(2+f). */
double fn_803FD650(double x) {
    DoubleBits exponent, bits;
    int k, hx, i, j;
    u32 lx;
    double f, s, z, w, t1, t2, r, hfsq, dk;
    bits.value = x;
    hx = bits.words.high;
    lx = bits.words.low;
    k = 0;
    if (hx < 0x00100000) {
        if (((hx & 0x7fffffff) | lx) == 0) return lbl_805A4D68 / lbl_805A12F8;
        if (hx < 0) {
            lbl_805A12E0 = 33;
            return (x - x) / lbl_805A12F8;
        }
        k = -54;
        x *= lbl_805A4D70;
        bits.value = x;
        hx = bits.words.high;
    }
    if (hx >= 0x7ff00000) return x + x;
    k += (hx >> 20) - 1023;
    hx &= 0x000fffff;
    i = (hx + 0x95f64) & 0x100000;
    bits.words.high = hx | (i ^ 0x3ff00000);
    x = bits.value;
    k += i >> 20;
    f = x - lbl_805A4D78;
    if ((0x000fffff & (2 + hx)) < 3) {
        if (f == lbl_805A12F8) {
            if (k == 0) return lbl_805A12F8;
            exponent.words.low = (u32)k ^ 0x80000000u;
            exponent.words.high = 0x43300000;
            dk = UnbiasExponent(exponent.value, lbl_805A4DE0);
            return lbl_805A4D80 * dk + lbl_805A4D88 * dk;
        }
        r = (lbl_805A4D90 - lbl_805A4D98 * f) * (f * f);
        if (k == 0) return f - r;
        exponent.words.low = (u32)k ^ 0x80000000u;
        exponent.words.high = 0x43300000;
        dk = UnbiasExponent(exponent.value, lbl_805A4DE0);
        return lbl_805A4D80 * dk - ((r - lbl_805A4D88 * dk) - f);
    }
    s = f / (lbl_805A4DA0 + f);
    exponent.words.low = (u32)k ^ 0x80000000u;
    exponent.words.high = 0x43300000;
    dk = UnbiasExponent(exponent.value, lbl_805A4DE0);
    z = s * s;
    i = hx - 0x6147a;
    w = z * z;
    j = 0x6b851 - hx;
    t1 = w * (lbl_805A4DA8 + w * (lbl_805A4DB0 + lbl_805A4DB8 * w));
    t2 = z * (lbl_805A4DC0 + w * (lbl_805A4DC8 + w * (lbl_805A4DD0 + lbl_805A4DD8 * w)));
    i |= j;
    r = t2 + t1;
    if (i > 0) {
        hfsq = lbl_805A4D90 * f;
        hfsq = hfsq * f;
        if (k == 0) return f - (hfsq - s * (hfsq + r));
        return lbl_805A4D80 * dk - ((hfsq - (s * (hfsq + r) + lbl_805A4D88 * dk)) - f);
    }
    if (k == 0) return f - s * (f - r);
    return lbl_805A4D80 * dk - ((s * (f - r) - lbl_805A4D88 * dk) - f);
}
