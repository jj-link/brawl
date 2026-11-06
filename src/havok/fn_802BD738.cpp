#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802BD804();
void fn_802BFA78();
void fn_802BFB08();
void fn_802BFB50();
void fn_802BD934();
void fn_802BED5C();
void fn_802BE124();
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

extern "C" void fn_802BD738(void* self) {
    Entry first(fn_802BD804, fn_802BFA78, fn_802BFB08, fn_802BFB50,
                true, false);
    fn_802CC0EC(self, &first, 6, 11);

    Entry second(fn_802BD934, fn_802BED5C, fn_802BE124, fn_802B7FD0,
                 false, false);
    fn_802CC0EC(self, &second, 11, 6);
}