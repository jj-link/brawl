#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802B4948();
void fn_802B6C64();
void fn_802B6CF4();
void fn_802B6D3C();
void fn_802B48CC();
void fn_802B4B1C();
void fn_802B52A0();
void fn_802B5B50();
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

extern "C" void fn_802B4800(void* self) {
    Entry first(fn_802B4948, fn_802B6C64, fn_802B6CF4, fn_802B6D3C,
                true, true);
    fn_802CC0EC(self, &first, 0x12, 0x15);

    Entry second(fn_802B48CC, fn_802B4B1C, fn_802B52A0, fn_802B5B50,
                 false, true);
    fn_802CC0EC(self, &second, 0x15, 0x12);
}
