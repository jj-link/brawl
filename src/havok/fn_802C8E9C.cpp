#pragma force_active on
#pragma use_lmw_stmw on

extern "C" {
void fn_802C9360();
void fn_802CA4D4();
void fn_802CA564();
void fn_802CA5AC();
void fn_802C9020();
void fn_802CA0D4();
void fn_802C9E4C();
void fn_802C9BBC();
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

extern "C" void fn_802C8E9C(void* self) {
    Entry first(fn_802C9360, fn_802CA4D4, fn_802CA564, fn_802CA5AC,
                true, true);
    fn_802CC0EC(self, &first, -1, 0x19);

    Entry second(fn_802C9020, fn_802CA0D4, fn_802C9E4C, fn_802C9BBC,
                 false, true);
    fn_802CC0EC(self, &second, 0x19, -1);
}