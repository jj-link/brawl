// MSL inverse-trigonometric helpers reconstructed from the Brawl instructions.
// Existing constant symbols remain owned by the shared runtime data units.
typedef unsigned long u32;

extern unsigned char lbl_8059FF68[];
extern double lbl_805A4C88, lbl_805A4C90, lbl_805A4C98, lbl_805A4CA0;
extern double lbl_805A4CA8, lbl_805A4CB0, lbl_805A4CB8, lbl_805A4CC0;
extern double lbl_805A4CC8, lbl_805A4CD0, lbl_805A4CD8, lbl_805A4CE0;
extern double lbl_805A4CE8, lbl_805A4CF0, lbl_805A4CF8, lbl_805A4D00;
extern double lbl_805A4D08, lbl_805A4D10, lbl_805A4D18, lbl_805A4D20;
extern double lbl_805A4D28, lbl_805A4D30, lbl_805A4D38, lbl_805A4D40;
extern double lbl_805A4D48, lbl_805A4D50, lbl_805A4D58, lbl_805A4D60;
extern double fn_80400D94(double);
extern double fn_8040012C(double);

double fn_803FCE18(double x)
{
    double t;
    double w;
    double p;
    double q;
    double c;
    double r;
    double s;
    int hx;
    int ix;
    u32* xp;

    xp = (u32*)&x;
    hx = xp[0];
    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        if (((ix - 0x3ff00000) | xp[1]) == 0) {
            return lbl_805A4C88 * x + lbl_805A4C90 * x;
        }
        return *(float*)lbl_8059FF68;
    }
    if (ix < 0x3fe00000) {
        if (ix < 0x3e400000) {
            if (lbl_805A4C98 + x > lbl_805A4CA0) {
                return x;
            }
        } else {
            t = x * x;
        }
        p = t * (lbl_805A4CA8 + t * (lbl_805A4CB0 + t * (lbl_805A4CB8 + t * (lbl_805A4CC0 + t * (lbl_805A4CC8 + lbl_805A4CD0 * t)))));
        q = lbl_805A4CA0 + t * (lbl_805A4CD8 + t * (lbl_805A4CE0 + t * (lbl_805A4CE8 + lbl_805A4CF0 * t)));
        w = p / q;
        return x + x * w;
    }
    w = lbl_805A4CA0 - __fabs(x);
    t = lbl_805A4CF8 * w;
    p = t * (lbl_805A4CA8 + t * (lbl_805A4CB0 + t * (lbl_805A4CB8 + t * (lbl_805A4CC0 + t * (lbl_805A4CC8 + lbl_805A4CD0 * t)))));
    q = lbl_805A4CA0 + t * (lbl_805A4CD8 + t * (lbl_805A4CE0 + t * (lbl_805A4CE8 + lbl_805A4CF0 * t)));
    s = fn_80400D94(t);
    if (ix >= 0x3fef3333) {
        w = p / q;
        t = lbl_805A4C88 - (lbl_805A4D00 * (s + s * w) - lbl_805A4C90);
    } else {
        w = s;
        ((u32*)&w)[1] = 0;
        c = (t - w * w) / (s + w);
        r = p / q;
        p = lbl_805A4D00 * s * r - (lbl_805A4C90 - lbl_805A4D00 * c);
        q = lbl_805A4D08 - lbl_805A4D00 * w;
        t = lbl_805A4D08 - (p - q);
    }
    if (hx > 0) {
        return t;
    }
    return -t;
}

double fn_803FD0B0(double y, double x)
{
    double z;
    int hx;
    int hy;
    int ix;
    int iy;
    int m;
    int k;
    u32 lx;
    u32 ly;
    u32* xp;
    u32* yp;

    xp = (u32*)&x;
    hx = xp[0];
    ix = hx & 0x7fffffff;
    lx = xp[1];
    yp = (u32*)&y;
    hy = yp[0];
    iy = hy & 0x7fffffff;
    ly = yp[1];
    if ((u32)(ix | ((lx | -lx) >> 31)) > 0x7ff00000UL ||
        (u32)(iy | ((ly | -ly) >> 31)) > 0x7ff00000UL) {
        return x + y;
    }
    if (((hx - 0x3ff00000) | lx) == 0) {
        return fn_8040012C(y);
    }
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
    if ((iy | ly) == 0) {
        switch (m) {
        case 0:
        case 1:
            return y;
        case 2:
            return lbl_805A4D10;
        case 3:
            return lbl_805A4D18;
        }
    }
    if ((ix | lx) == 0) {
        if (hy < 0) {
            return lbl_805A4D20;
        }
        return lbl_805A4D28;
    }
    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (m) {
            case 0: return lbl_805A4D30;
            case 1: return lbl_805A4D38;
            case 2: return lbl_805A4D40;
            case 3: return lbl_805A4D48;
            }
        } else {
            switch (m) {
            case 0: return lbl_805A4D50;
            case 1: return lbl_805A4D58;
            case 2: return lbl_805A4D10;
            case 3: return lbl_805A4D18;
            }
        }
    }
    if (iy == 0x7ff00000) {
        if (hy < 0) {
            return lbl_805A4D20;
        }
        return lbl_805A4D28;
    }
    k = (iy - ix) >> 20;
    if (k > 60) {
        z = lbl_805A4D28;
    } else if (hx < 0 && k < -60) {
        z = lbl_805A4D50;
    } else {
        z = fn_8040012C(__fabs(y / x));
    }
    switch (m) {
    case 0:
        return z;
    case 1:
        ((u32*)&z)[0] ^= 0x80000000UL;
        return z;
    case 2:
        return lbl_805A4D10 - (z - lbl_805A4D60);
    default:
        return (z - lbl_805A4D60) - lbl_805A4D10;
    }
}
