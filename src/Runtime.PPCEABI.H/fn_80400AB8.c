#pragma force_active on
extern const double lbl_805A5100;
extern int fn_803FE260(double, double *);
extern double fn_803FFED4(double, double, int);

double fn_80400AB8(double value) {
    double remainder[2];
    double zero = lbl_805A5100;
    int magnitude = ((int*)&value)[0] & 0x7fffffff;
    int quadrant;

    if (magnitude <= 0x3fe921fb) {
        return fn_803FFED4(value, zero, 1);
    } else if (magnitude >= 0x7ff00000) {
        return value - value;
    } else {
        quadrant = fn_803FE260(value, remainder);
        return fn_803FFED4(remainder[0], remainder[1], 1 - ((quadrant & 1) << 1));
    }
}