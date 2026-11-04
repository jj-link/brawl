#pragma force_active on
extern const double lbl_805A50B8;
extern const double lbl_805A50C0;

double fn_804005AC(double x) {
    int high;
    unsigned int low;
    int exponent;
    unsigned int mask, rounded;
    high = ((int*)&x)[0];
    low = ((unsigned int*)&x)[1];
    exponent = ((high >> 20) & 0x7ff) - 1023;
    if (exponent < 20) {
        if (exponent < 0) {
            if (lbl_805A50B8 + x > lbl_805A50C0) {
                if (high >= 0) {
                    low = 0;
                    high = 0;
                } else if ((high & 0x7fffffff) | low) {
                    high = 0xbff00000;
                    low = 0;
                }
            }
        } else {
            mask = 0x000fffff >> exponent;
            if (((high & mask) | low) == 0) return x;
            if (lbl_805A50B8 + x > lbl_805A50C0) {
                if (high < 0) high += 0x00100000 >> exponent;
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
        if (lbl_805A50B8 + x > lbl_805A50C0) {
            if (high < 0) {
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
    ((unsigned int*)&x)[1] = low;
    return x;
}