/* Adapted from OpenRVL/src/stl/k_rem_pio2.c in this repository.
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunSoft, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Brawl's constants and runtime entry points retain their existing ownership.
 */
extern const int lbl_80420318[4];
extern const double lbl_80420328[8];
extern const double lbl_805A4FC8, lbl_805A4FD0, lbl_805A4FD8;
extern const double lbl_805A4FE0, lbl_805A4FE8, lbl_805A4FF0, lbl_805A4FF8;
extern double fn_803FC9BC(double, int);
extern double fn_804005AC(double);

#define zero lbl_805A4FC8
#define one lbl_805A4FF8
#define two24 lbl_805A4FD8
#define twon24 lbl_805A4FD0

/* Reduce a positive value represented by nx 24-bit pieces modulo pi/2.
 * prec selects one, two, or three output terms; return the quotient modulo 8.
 */
int fn_803FE708(double* x, double* y, int e0, int nx, int prec, const int* ipio2) {
    int jz, jx, jv, jp, jk, carry, n, iq[20], i, j, k, m, q0, ih;
    double z, fw, f[20], fq[20], q[20];

    jk = lbl_80420318[prec];
    jp = jk;
    jx = nx - 1;
    jv = (e0 - 3) / 24;
    if (jv < 0) jv = 0;
    q0 = e0 - 24 * (jv + 1);
    j = jv - jx;
    m = jx + jk;
    for (i = 0; i <= m; i++, j++) f[i] = j < 0 ? zero : (double)ipio2[j];
    for (i = 0; i <= jk; i++) {
        for (j = 0, fw = zero; j <= jx; j++) fw += x[j] * f[jx + i - j];
        q[i] = fw;
    }
    jz = jk;
recompute:
    for (i = 0, j = jz, z = q[jz]; j > 0; i++, j--) {
        fw = (double)(int)(twon24 * z);
        iq[i] = (int)(z - two24 * fw);
        z = q[j - 1] + fw;
    }
    z = fn_803FC9BC(z, q0);
    z -= lbl_805A4FE0 * fn_804005AC(lbl_805A4FE8 * z);
    n = (int)z;
    z -= (double)n;
    ih = 0;
    if (q0 > 0) {
        i = iq[jz - 1] >> (24 - q0);
        n += i;
        iq[jz - 1] -= i << (24 - q0);
        ih = iq[jz - 1] >> (23 - q0);
    } else if (q0 == 0) {
        ih = iq[jz - 1] >> 23;
    } else if (z >= lbl_805A4FF0) {
        ih = 2;
    }
    if (ih > 0) {
        n += 1;
        carry = 0;
        for (i = 0; i < jz; i++) {
            j = iq[i];
            if (carry == 0) {
                if (j != 0) {
                    carry = 1;
                    iq[i] = 0x1000000 - j;
                }
            } else {
                iq[i] = 0xffffff - j;
            }
        }
        if (q0 > 0) {
            switch (q0) {
            case 1: iq[jz - 1] &= 0x7fffff; break;
            case 2: iq[jz - 1] &= 0x3fffff; break;
            }
        }
        if (ih == 2) {
            z = one - z;
            if (carry != 0) z -= fn_803FC9BC(one, q0);
        }
    }
    if (zero == z) {
        j = 0;
        for (i = jz - 1; i >= jk; i--) j |= iq[i];
        if (j == 0) {
            for (k = 1; iq[jk - k] == 0; k++) {}
            for (i = jz + 1; i <= jz + k; i++) {
                f[jx + i] = (double)ipio2[jv + i];
                for (j = 0, fw = zero; j <= jx; j++) fw += x[j] * f[jx + i - j];
                q[i] = fw;
            }
            jz += k;
            goto recompute;
        }
    }
    if (zero == z) {
        jz -= 1;
        q0 -= 24;
        while (iq[jz] == 0) {
            jz--;
            q0 -= 24;
        }
    } else {
        z = fn_803FC9BC(z, -q0);
        if (z >= two24) {
            fw = (double)(int)(twon24 * z);
            iq[jz] = (int)(z - two24 * fw);
            jz += 1;
            q0 += 24;
            iq[jz] = (int)fw;
        } else {
            iq[jz] = (int)z;
        }
    }
    fw = fn_803FC9BC(one, q0);
    for (i = jz; i >= 0; i--) {
        q[i] = fw * (double)iq[i];
        fw *= twon24;
    }
    for (i = jz; i >= 0; i--) {
        for (fw = zero, k = 0; k <= jp && k <= jz - i; k++) fw += lbl_80420328[k] * q[i + k];
        fq[jz - i] = fw;
    }
    switch (prec) {
    case 0:
        fw = zero;
        for (i = jz; i >= 0; i--) fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        break;
    case 1:
    case 2:
        fw = zero;
        for (i = jz; i >= 0; i--) fw += fq[i];
        y[0] = ih == 0 ? fw : -fw;
        fw = fq[0] - fw;
        for (i = 1; i <= jz; i++) fw += fq[i];
        y[1] = ih == 0 ? fw : -fw;
        break;
    case 3:
        for (i = jz; i > 0; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (i = jz; i > 1; i--) {
            fw = fq[i - 1] + fq[i];
            fq[i] += fq[i - 1] - fw;
            fq[i - 1] = fw;
        }
        for (fw = zero, i = jz; i >= 2; i--) fw += fq[i];
        if (ih == 0) {
            y[0] = fq[0];
            y[1] = fq[1];
            y[2] = fw;
        } else {
            y[0] = -fq[0];
            y[1] = -fq[1];
            y[2] = -fw;
        }
    }
    return n & 7;
}
