// Runtime.PPCEABI.H/fn_803FCB54.c
// MSL acos polynomial and square-root correction.

typedef unsigned long u32;

extern unsigned char lbl_8059FF68[];
extern double lbl_805A4C00, lbl_805A4C08, lbl_805A4C10;
extern double lbl_805A4C18, lbl_805A4C20, lbl_805A4C28, lbl_805A4C30;
extern double lbl_805A4C38, lbl_805A4C40, lbl_805A4C48, lbl_805A4C50;
extern double lbl_805A4C58, lbl_805A4C60, lbl_805A4C68, lbl_805A4C70;
extern double lbl_805A4C78, lbl_805A4C80;
extern double fn_80400D94(double x);

double fn_803FCB54(double x) {
    int hx;
    int ix;
    double z;
    double p;
    double q;
    double r;
    double w;
    double s;
    double c;
    double df;
    u32* xp;

    xp = (u32*)&x;
    hx = (int)xp[0];
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        if (((ix - 0x3ff00000) | (int)xp[1]) == 0) {
            if (hx > 0) {
                return lbl_805A4C00;
            }
            return lbl_805A4C08;
        }
        return *(float*)lbl_8059FF68;
    }
    if (ix < 0x3fe00000) {
        if (ix <= 0x3c600000) {
            return lbl_805A4C10;
        }
        z = x * x;
        p = z * (lbl_805A4C18 + z * (lbl_805A4C20 + z * (lbl_805A4C28 + z * (lbl_805A4C30 + z * (lbl_805A4C38 + lbl_805A4C40 * z)))));
        q = lbl_805A4C48 + z * (lbl_805A4C50 + z * (lbl_805A4C58 + z * (lbl_805A4C60 + lbl_805A4C68 * z)));
        r = p / q;
        return lbl_805A4C10 - (x - (lbl_805A4C70 - x * r));
    } else if (hx < 0) {
        z = (lbl_805A4C48 + x) * lbl_805A4C78;
        p = z * (lbl_805A4C18 + z * (lbl_805A4C20 + z * (lbl_805A4C28 + z * (lbl_805A4C30 + z * (lbl_805A4C38 + lbl_805A4C40 * z)))));
        q = lbl_805A4C48 + z * (lbl_805A4C50 + z * (lbl_805A4C58 + z * (lbl_805A4C60 + lbl_805A4C68 * z)));
        s = fn_80400D94(z);
        r = p / q;
        w = r * s - lbl_805A4C70;
        return lbl_805A4C08 - lbl_805A4C80 * (s + w);
    } else {
        z = (lbl_805A4C48 - x) * lbl_805A4C78;
        s = fn_80400D94(z);
        df = s;
        ((u32*)&df)[1] = 0;
        c = (z - df * df) / (s + df);
        p = z * (lbl_805A4C18 + z * (lbl_805A4C20 + z * (lbl_805A4C28 + z * (lbl_805A4C30 + z * (lbl_805A4C38 + lbl_805A4C40 * z)))));
        q = lbl_805A4C48 + z * (lbl_805A4C50 + z * (lbl_805A4C58 + z * (lbl_805A4C60 + lbl_805A4C68 * z)));
        r = p / q;
        w = r * s + c;
        return lbl_805A4C80 * (df + w);
    }
}
