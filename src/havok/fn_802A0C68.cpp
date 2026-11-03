#include <types.h>
#pragma force_active on

extern "C" {
void fn_802A0CD0();
void fn_802A1858();
void fn_802A13B4();
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

extern "C" void fn_802A0C68(void* self) {
    Entry first(fn_802A0CD0, fn_802A1858, fn_802A13B4, fn_802B7FD0,
                false, false);
    fn_802CC0EC(self, &first, 7, 7);
}
