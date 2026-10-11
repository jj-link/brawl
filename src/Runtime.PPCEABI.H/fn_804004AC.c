extern const double lbl_805A50B0;
extern int fn_803FE260(double value, double* remainder);
extern double fn_803FE5F8(double value, double tail);
extern double fn_803FFE14(double value, double tail, int tail_present);

typedef union DoubleBits {
    double value;
    unsigned long words[2];
} DoubleBits;

// Copy only the sign bit, preserving the magnitude's payload and low word.
double fn_804004AC(double magnitude, double sign) {
    DoubleBits y;
    DoubleBits x;
    x.value = magnitude;
    y.value = sign;
    x.words[0] = (x.words[0] & 0x7fffffffUL) | (y.words[0] & 0x80000000UL);
    return x.value;
}

double cos(double value) {
    double remainder[2];
    double zero = lbl_805A50B0;
    int magnitude = ((int*)&value)[0] & 0x7fffffff;
    int quadrant;

    if (magnitude <= 0x3fe921fb) {
        return fn_803FE5F8(value, zero);
    } else if (magnitude >= 0x7ff00000) {
        return value - value;
    } else {
        quadrant = fn_803FE260(value, remainder);
        switch (quadrant & 3) {
        case 0:
            return fn_803FE5F8(remainder[0], remainder[1]);
        case 1:
            return -fn_803FFE14(remainder[0], remainder[1], 1);
        case 2:
            return -fn_803FE5F8(remainder[0], remainder[1]);
        default:
            return fn_803FFE14(remainder[0], remainder[1], 1);
        }
    }
}
