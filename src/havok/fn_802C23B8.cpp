#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802C2484();
void fn_802C3AB0();
void fn_802C3B40();
void fn_802C3B88();
void fn_802C2558();
void fn_802C3758();
void fn_802C31C8();
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

extern "C" void fn_802C23B8(void* self) {
    Entry first(fn_802C2484, fn_802C3AB0, fn_802C3B40, fn_802C3B88,
                true, false);
    fn_802CC0EC(self, &first, 7, 4);

    Entry second(fn_802C2558, fn_802C3758, fn_802C31C8, fn_802B7FD0,
                 false, false);
    fn_802CC0EC(self, &second, 4, 7);
}