#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802C7064();
void fn_802C83DC();
void fn_802C846C();
void fn_802C84B4();
void fn_802C7178();
void fn_802C7D04();
void fn_802C76E4();
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

extern "C" void fn_802C6F98(void* self) {
    Entry first(fn_802C7064, fn_802C83DC, fn_802C846C, fn_802C84B4,
                true, false);
    fn_802CC0EC(self, &first, 6, 4);

    Entry second(fn_802C7178, fn_802C7D04, fn_802C76E4, fn_802B7FD0,
                 false, false);
    fn_802CC0EC(self, &second, 4, 6);
}
