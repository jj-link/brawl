#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802BAD0C();
void fn_802BD2C0();
void fn_802BD350();
void fn_802BD398();
void fn_802BAC90();
void fn_802BCCE0();
void fn_802BBC8C();
void fn_802BC4A8();
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

extern "C" void fn_802BABC4(void* self) {
    Entry first(fn_802BAD0C, fn_802BD2C0, fn_802BD350, fn_802BD398,
                true, true);
    fn_802CC0EC(self, &first, -1, 0xB);

    Entry second(fn_802BAC90, fn_802BCCE0, fn_802BBC8C, fn_802BC4A8,
                 false, true);
    fn_802CC0EC(self, &second, 0xB, -1);
}
