#pragma force_active on
typedef signed long long s64;
typedef unsigned char u8;
struct Cal { int sec, min, hour, mday, mon, year, wday, yday, msec, usec; };
extern "C" s64 fn_801504AC(u8*);
extern "C" s64 fn_8014F710(void);
extern "C" s64 fn_8014F79C(void);
extern "C" s64 fn_8014FB0C(void);
extern "C" int fn_8014F6E4(void);
extern "C" void fn_801E1D80(s64, Cal*);

extern "C" int fn_80154CD8() {
    int r = 0;
    u8 ok;
    s64 t = fn_801504AC(&ok);
    if (ok) {
        s64 a = fn_8014F710();
        s64 b = fn_8014F79C();
        s64 c = fn_8014FB0C();
        if (a != 0 && b != 0) {
            if (!(t < a) && !(b < t)) {
                if (fn_8014F6E4()) {
                    r = 1;
                } else {
                    Cal x, y;
                    fn_801E1D80(t, &x);
                    fn_801E1D80(c, &y);
                    if (x.year != y.year || x.mon != y.mon || x.mday != y.mday) r = 1;
                }
            }
        }
    }
    return r;
}