#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802B9168();
void fn_802BA3AC();
void fn_802BA43C();
void fn_802BA484();
void fn_802B9284();
void fn_802B9BA0();
void fn_802B9798();
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

extern "C" void fn_802B8E78(void* self) {
    Entry first(fn_802B9168, fn_802BA3AC, fn_802BA43C, fn_802BA484,
                true, true);
    fn_802CC0EC(self, &first, 1, 0x11);

    Entry second(fn_802B9284, fn_802B9BA0, fn_802B9798, fn_802B7FD0,
                 false, true);
    fn_802CC0EC(self, &second, 0x11, 1);
}
