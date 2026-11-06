#include <types.h>
#pragma force_active on

extern "C" {
void fn_802AA9B8();
void fn_802AB66C();
void fn_802AB0FC();
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

extern "C" void fn_802AAA38(void* self) {
    Entry first(fn_802AA9B8, fn_802AB66C, fn_802AB0FC, fn_802B7FD0,
                false, false);
    fn_802CC0EC(self, &first, 8, 8);
}
