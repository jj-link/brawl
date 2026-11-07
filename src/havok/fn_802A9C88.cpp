#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802A9D54();
void fn_802A8984();
void fn_802A8A14();
void fn_802A8A5C();
void fn_802A9E74();
void fn_802A83F8();
void fn_802A7F30();
void fn_802A78F8();
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

extern "C" void fn_802A9C88(void* self) {
    Entry first(fn_802A9D54, fn_802A8984, fn_802A8A14, fn_802A8A5C,
                true, true);
    fn_802CC0EC(self, &first, 3, 0x11);

    Entry second(fn_802A9E74, fn_802A83F8, fn_802A7F30, fn_802A78F8,
                 false, true);
    fn_802CC0EC(self, &second, 0x11, 3);
}
