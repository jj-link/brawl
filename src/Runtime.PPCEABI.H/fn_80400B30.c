// Math entry points forwarding to their shared implementations.
extern double fn_803FCB54(double);
extern double fn_803FCE18(double);
extern double fn_803FD0B0(double, double);
extern double fn_803FD320(double, double);
extern double fn_803FD904(double);
extern double fn_803FDA18(double, double);

double fn_80400B30(double x) { return fn_803FCB54(x); }
double fn_80400B34(double x) { return fn_803FCE18(x); }
double atan2(double y, double x) { return fn_803FD0B0(y, x); }
double fn_80400B3C(double x, double y) { return fn_803FD320(x, y); }
double fn_80400B40(double x) { return fn_803FD904(x); }
double fn_80400B44(double x, double y) { return fn_803FDA18(x, y); }
