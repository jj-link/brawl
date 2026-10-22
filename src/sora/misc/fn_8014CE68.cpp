#pragma force_active on
extern "C" {
extern int fn_8014DD34(int, int);
extern int fn_803995F8(int *);

long long fn_8014CE68(int a) {
    long long v;
    if (fn_8014DD34(a, 1) == 0) {
        return 0;
    }
    if (fn_803995F8((int *)&v) != 0) {
        v = 0;
    }
    return v;
}
}
