#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802C3FB0();
void fn_802C59C4();
void fn_802C5A54();
void fn_802C5A9C();
void fn_802C4084();
void fn_802C4E34();
void fn_802C47CC();
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

extern "C" void fn_802C3EE4(void* self) {
    Entry first(fn_802C3FB0, fn_802C59C4, fn_802C5A54, fn_802C5A9C,
                true, false);
    fn_802CC0EC(self, &first, 8, 4);

    Entry second(fn_802C4084, fn_802C4E34, fn_802C47CC, fn_802B7FD0,
                 false, false);
    fn_802CC0EC(self, &second, 4, 8);
}