#include <types.h>
#pragma force_active on

extern "C" {
void fn_802B3700();
void fn_802B2490();
void fn_802B1C3C();
void fn_802B7FD0();
}

typedef void (*Callback)();

struct Entry {
    Callback a, b, c, d;
    bool e, f;

    Entry(Callback aa, Callback bb, Callback cc, Callback dd,
          bool ee, bool ff) : e(false) {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        e = ee;
        f = ff;
    }
};

extern "C" void fn_802CC0EC(void*, const Entry*, int, int);

extern "C" void fn_802B3694(void* self) {
    Entry first(fn_802B3700, fn_802B2490, fn_802B1C3C, fn_802B7FD0,
                false, true);
    fn_802CC0EC(self, &first, 1, 1);
}